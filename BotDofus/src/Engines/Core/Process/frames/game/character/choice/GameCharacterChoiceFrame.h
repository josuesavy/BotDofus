#ifndef GAMECHARACTERCHOICEFRAME_H
#define GAMECHARACTERCHOICEFRAME_H

#include <QInputDialog>
#include <QtSql/QtSql>

#include "src/Engines/Core/Process/frames/AbstractFrame.h"
#include "src/Engines/Core/Process/Managers/connection/ConnectionManager.h"
#include "src/Engines/Core/Process/Managers/group/GroupManager.h"

class GameCharacterChoiceFrame : public AbstractFrame
{
public:
    GameCharacterChoiceFrame(QMap<SocketIO*, BotData> *connectionsData, ConnectionManager *connectionManager, GroupManager *groupManager);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);

private:
    ConnectionManager *m_connectionManager;
    GroupManager *m_groupManager;
};

#endif // GAMECHARACTERCHOICEFRAME_H
