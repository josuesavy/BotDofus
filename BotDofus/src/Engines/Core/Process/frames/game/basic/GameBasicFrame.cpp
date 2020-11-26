#include "GameBasicFrame.h"

GameBasicFrame::GameBasicFrame(QMap<SocketIO *, BotData> *connectionsData, ConnectionManager *connectionManager):
    AbstractFrame(ModuleType::CONNECTION, connectionsData),
    m_connectionManager(connectionManager)
{

}

void GameBasicFrame::reset(SocketIO *sender)
{

}

bool GameBasicFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::BASICACKMESSAGE:
    {
        if(m_botData[sender].scriptData.scriptMaxTime != INVALID &&
                m_botData[sender].scriptData.scriptMaxTime < m_botData[sender].scriptData.scriptTimer.elapsed() &&
                sender->getLatencyList().last() <= m_botData[sender].scriptData.scriptMaxTime)
        {
            m_botData[sender].scriptData.scriptMaxTime = INVALID;
            error(sender)<<"Il semblerait que le bot soit bloqué, tentative de relance du script...";
            m_connectionManager->reconnect(sender);
        }
    }
        break;

    case MessageEnum::BASICLATENCYSTATSREQUESTMESSAGE:
    {
        BasicLatencyStatsMessage answer;
        qDebug()<<"Stats connexion (en ms) - AVG"<<sender->getLatencyAverage()<<"SAMPLES"<<sender->getSampleCount()<<"MAX"<<sender->getMaxLatency();

        if(sender->getLatencyAverage() > 32767)
            answer.latency = 32767;
        else
            answer.latency = sender->getLatencyAverage();

        answer.sampleCount = sender->getSampleCount();
        answer.max = sender->getMaxLatency();

        sender->send(answer);
    }
        break;

    case MessageEnum::BASICNOOPERATIONMESSAGE:
        break;

    case MessageEnum::BASICTIMEMESSAGE:
        break;

    case MessageEnum::SEQUENCENUMBERREQUESTMESSAGE:
    {
        if (m_botData[sender].connectionData.greetingMessageIsInitialized > 1)
        {
            m_botData[sender].connectionData.sequenceNumber++;
            SequenceNumberMessage answer;
            answer.number = m_botData[sender].connectionData.sequenceNumber;
            sender->send(answer);
        }
    }
        break;

    case MessageEnum::TEXTINFORMATIONMESSAGE:
    {
        if (m_botData[sender].connectionData.greetingMessageIsInitialized == 0)
        {
            m_botData[sender].connectionData.greetingMessageIsInitialized++;

            FriendsGetListMessage answer1;
            sender->send(answer1);

            AcquaintancesGetListMessage answer2;
            sender->send(answer2);

            IgnoredGetListMessage answer3;
            sender->send(answer3);

            ClientKeyMessage answer4;
            answer4.key = m_connectionManager->getFlashKey();
            sender->send(answer4);

            GameContextCreateRequestMessage answer5;
            sender->send(answer5);

            ChannelEnablingMessage answer6;
            for (int i = 0; i < 13; i++)
            {
                answer6.channel = i;
                answer6.enable = true;
                sender->send(answer6);
            }
        }

        else if (m_botData[sender].connectionData.greetingMessageIsInitialized == 1)
        {
            m_botData[sender].connectionData.greetingMessageIsInitialized++;
            m_botData[sender].connectionData.sequenceNumber++;
            SequenceNumberMessage answer;
            answer.number = m_botData[sender].connectionData.sequenceNumber;
            sender->send(answer);
        }

        TextInformationMessage message;
        message.deserialize(&reader);

        QSharedPointer<InfoMessageData> infoData = qSharedPointerCast<InfoMessageData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::INFOMESSAGES, message.msgType*10000 + message.msgId));
        QString output = infoData->getText();
        output = ParamsDecoder::applyParams(output, message.parameters);

        qDebug()<<"TextInformationMessage -"<<output<<" Params -"<<message.parameters;

        switch((TextInformationTypeEnum)infoData->getTypeId())
        {
        case TextInformationTypeEnum::TEXT_ENTITY_TALK:
            break;

        case TextInformationTypeEnum::TEXT_INFORMATION_ERROR:
            error(sender)<<output.replace("\n"," ");
            break;

        case TextInformationTypeEnum::TEXT_INFORMATION_FIGHT:
            action(sender)<<output;
            break;

        case TextInformationTypeEnum::TEXT_INFORMATION_FIGHT_LOG:
            log(sender, CHANNELFIGHTLOG) << output;
            break;

        case TextInformationTypeEnum::TEXT_INFORMATION_MESSAGE:
            action(sender)<<output;
            break;

        case TextInformationTypeEnum::TEXT_INFORMATION_POPUP:
            break;

        case TextInformationTypeEnum::TEXT_INFORMATION_PVP:
            log(sender, CHANNELALLIANCE) << output;
            break;

        case TextInformationTypeEnum::TEXT_LIVING_OBJECT:
            log(sender, CHANNELPRIVATE) << output;
            break;
        }
    }
        break;
    }

    return messageFound;
}
