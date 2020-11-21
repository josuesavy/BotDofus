#include "GameContextRoleplayObjectsFrame.h"

GameContextRoleplayObjectsFrame::GameContextRoleplayObjectsFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(ModuleType::CONNECTION, connectionsData)
{

}

void GameContextRoleplayObjectsFrame::reset(SocketIO *sender)
{

}

bool GameContextRoleplayObjectsFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::OBJECTGROUNDADDEDMESSAGE:
    {
        ObjectGroundAddedMessage message;
        message.deserialize(&reader);

        m_botData[sender].mapData.objectGroundListAdded.insert(message.cellId, message.objectGID);
    }
        break;

    case MessageEnum::OBJECTGROUNDLISTADDEDMESSAGE:
    {
        m_botData[sender].mapData.objectGroundListAdded.clear();

        ObjectGroundListAddedMessage message;
        message.deserialize(&reader);

        for(int i = 0; i < message.cells.size(); i++)
            m_botData[sender].mapData.objectGroundListAdded.insert(message.cells.at(i), message.referenceIds.at(i));
    }
        break;

    case MessageEnum::OBJECTGROUNDREMOVEDMESSAGE:
    {
        ObjectGroundRemovedMessage message;
        message.deserialize(&reader);

        m_botData[sender].mapData.objectGroundListAdded.remove(message.cell);
    }
        break;
    }

    return messageFound;
}
