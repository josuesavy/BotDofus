#include "GameCharacterChoiceFrame.h"

GameCharacterChoiceFrame::GameCharacterChoiceFrame(QMap<SocketIO *, BotData> *connectionsData, ConnectionManager *connectionManager, GroupManager *groupManager):
    AbstractFrame(connectionsData),
    m_connectionManager(connectionManager),
    m_groupManager(groupManager)
{

}

bool GameCharacterChoiceFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::BASICCHARACTERSLISTMESSAGE:
    {
        BasicCharactersListMessage message;
        message.deserialize(&reader);

        foreach (QSharedPointer<CharacterBaseInformations> infos, message.characters)
        {
            //debug(sender)<<"\t->"<<infos->name<<"niveau"<<infos->level;

            if (infos->name == m_botData[sender].connectionData.connectionInfos.character)
            {
                m_botData[sender].mapData.botId = infos->id;
                m_botData[sender].playerData.breed = infos->breed;
                m_botData[sender].playerData.sex = infos->sex;
            }
        }

    }
        break;

    case MessageEnum::CHARACTERSELECTEDERRORMESSAGE:
    {
        CharacterSelectedErrorMessage message;
        message.deserialize(&reader);

        error(sender)<<"Sélection du personnage refusé.";
        sender->disconnect();
    }
        break;

    case MessageEnum::CHARACTERSELECTEDFORCEMESSAGE:
    {
        if(!m_botData[sender].connectionData.connectionInfos.masterGroup.isEmpty())
            m_groupManager->updateTeams();

        CharacterSelectedForceMessage message;
        message.deserialize(&reader);

        m_botData[sender].mapData.botId = message.id;

        CharacterSelectedForceReadyMessage answer;
        sender->send(answer);

        m_botData[sender].connectionData.connectionState = ConnectionState::CONNECTED;

        FriendsGetListMessage answer1;
        sender->send(answer1);

        IgnoredGetListMessage answer2;
        sender->send(answer2);

        ClientKeyMessage answer3;
        answer3.key = m_connectionManager->getFlashKey();
        sender->send(answer3);

        GameContextCreateRequestMessage answer4;
        sender->send(answer4);

        ChannelEnablingMessage answer5;
        for (int i = 0; i < 13; i++)
        {
            answer5.channel = i;
            answer5.enable = true;
            sender->send(answer5);
        }
    }
        break;

    case MessageEnum::CHARACTERSELECTEDSUCCESSMESSAGE:
    {
        CharacterSelectedSuccessMessage message;
        message.deserialize(&reader);

        m_botData[sender].connectionData.connectionInfos.character = message.infos->name;
        m_botData[sender].mapData.botId = message.infos->id;
        m_botData[sender].playerData.breed = message.infos->breed;
        m_botData[sender].playerData.sex = message.infos->sex;

        QSqlQuery query;
        query.prepare("UPDATE accounts SET character = :character WHERE login = :login");
        query.bindValue(":character", m_botData[sender].connectionData.connectionInfos.character);
        query.bindValue(":login", m_botData[sender].connectionData.connectionInfos.login);
        query.exec();

        info(sender)<<"Personnage"<<message.infos->name<<"sélectionné.";
    }
        break;

    case MessageEnum::CHARACTERSLISTMESSAGE:
    {
        action(sender)<<"Réception de la liste des personnages.";

        CharactersListMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].connectionData.connectionInfos.needToCreateCharacter && !m_botData[sender].connectionData.connectionInfos.characterCreated)
        {
            if(m_botData[sender].connectionData.connectionInfos.creation.name.isEmpty())
            {
                CharacterNameSuggestionRequestMessage cnsrmsg;
                sender->send(cnsrmsg);
            }

            else
            {
                action(sender) << "Création du personnage "+m_botData[sender].connectionData.connectionInfos.creation.name+"..";
                CharacterCreationRequestMessage ccrmsg;
                ccrmsg.name = m_botData[sender].connectionData.connectionInfos.creation.name;
                ccrmsg.breed = m_botData[sender].connectionData.connectionInfos.creation.breed;
                ccrmsg.sex = m_botData[sender].connectionData.connectionInfos.creation.sex;
                ccrmsg.colors = m_botData[sender].connectionData.connectionInfos.creation.colors;
                ccrmsg.cosmeticId = m_botData[sender].connectionData.connectionInfos.creation.head;

                sender->send(ccrmsg);
            }
        }

        else if(!m_botData[sender].connectionData.connectionInfos.needToCreateCharacter && m_botData[sender].connectionData.connectionInfos.characterCreated)
        {
            if (!message.characters.isEmpty())
            {
                action(sender) << "Sélection du personnage" << message.characters.first()->name + "...";
                m_botData[sender].playerData.breed = message.characters.first()->breed;
                m_botData[sender].playerData.sex = message.characters.first()->sex;

                CharacterFirstSelectionMessage answer;
                answer.doTutorial = false;
                answer.id = message.characters.first()->id;
                sender->send(answer);
            }

            else
            {
                error(sender)<<"Vous n'avez pas de personnage sur ce serveur.";
                sender->disconnect();
            }
        }

        else if(m_botData[sender].connectionData.connectionInfos.connectionTo == ConnectionTo::CHARACTER || m_botData[sender].connectionData.connectionInfos.connectionTo == ConnectionTo::SERVER || m_botData[sender].connectionData.connectionInfos.character.isEmpty() && !message.characters.isEmpty())
        {
            TreeWidgetDialog treeWidgetDialog;
            treeWidgetDialog.setParent(nullptr, Qt::Dialog);

            QString path;
            QSqlQuery query;
            query.prepare("SELECT d2p FROM globalParameters");
            if(query.exec())
            {
                while(query.next())
                {
                    path = query.value(0).toString();
                }
            }

            foreach(QSharedPointer<CharacterBaseInformations> infos, message.characters)
            {
                QPair<double, QPair<QIcon, QString>> serverItem;
                serverItem.first = infos->id;
                serverItem.second.first = QIcon(QString("%1/gfx/heads/SmallHead_%2%3.png").arg(path).arg(infos->breed).arg(infos->sex));
                serverItem.second.second = QString("%1 (%2)").arg(infos->name).arg(infos->level);

                treeWidgetDialog.addItem(serverItem);
            }

            if(treeWidgetDialog.exec() == QDialog::Accepted)
            {
                QPair<double, QPair<QIcon, QString>> characterItem;
                characterItem = treeWidgetDialog.getItemSelected();

                action(sender) << "Sélection du personnage" << characterItem.second.second.split('(').at(0) + "...";
                CharacterSelectionMessage answer;
                answer.id = characterItem.first;
                sender->send(answer);
            }
            else
                sender->disconnect();
        }

        else if(message.characters.isEmpty())
        {
            error(sender)<<"Vous n'avez pas de personnage sur ce serveur.";
            sender->disconnect();
        }

        else
        {
            action(sender) << "Sélection du personnage" << m_botData[sender].connectionData.connectionInfos.character + "...";

            foreach (QSharedPointer<CharacterBaseInformations> infos, message.characters)
            {
                if (infos->name == m_botData[sender].connectionData.connectionInfos.character)
                {
                    m_botData[sender].mapData.botId = infos->id;
                    m_botData[sender].playerData.breed = infos->breed;
                    m_botData[sender].playerData.sex = infos->sex;
                }
            }

            if (m_botData[sender].mapData.botId != INVALID)
            {
                CharacterSelectionMessage answer;
                answer.id = m_botData[sender].mapData.botId;
                sender->send(answer);
            }

            else
            {
                error(sender)<<"Le personnage"<<m_botData[sender].connectionData.connectionInfos.character<<"n'existe pas ou n'est pas sur ce serveur.";
                sender->disconnect();
            }
        }
    }
        break;

    case MessageEnum::CHARACTERSLISTERRORMESSAGE:
    {
        error(sender) << "La liste des personnages n'a pas pu être récupérée.";

        m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
        sender->disconnect();
    }
        break;
    }

    return messageFound;
}
