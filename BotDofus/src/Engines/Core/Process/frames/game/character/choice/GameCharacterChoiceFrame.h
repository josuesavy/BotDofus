#ifndef GAMECHARACTERCHOICEFRAME_H
#define GAMECHARACTERCHOICEFRAME_H

#include <QInputDialog>
#include <QtSql/QtSql>

#include "src/Engines/Core/Process/Frames/AbstractFrame.h"
#include "src/Engines/Core/Process/Managers/connection/ConnectionManager.h"
#include "src/Engines/Core/Process/Managers/group/GroupManager.h"

class GameCharacterChoiceFrame : public AbstractFrame
{
public:
    GameCharacterChoiceFrame(QMap<SocketIO*, BotData> *connectionsData, GroupManager *groupManager);

    /*!
     * \brief Reset the module
     * \param sender Bot's particular connection
     */
    virtual void reset(SocketIO *sender);


    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);

private:
    GroupManager *m_groupManager;
};

#endif // GAMECHARACTERCHOICEFRAME_H
