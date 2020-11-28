#ifndef GAMEINTERACTIVEFRAME_H
#define GAMEINTERACTIVEFRAME_H

#include "src/Engines/Core/Process/frames/AbstractFrame.h"
#include "src/Engines/Core/Process/Managers/interaction/InteractionManager.h"
#include "src/Engines/Core/Process/Managers/farm/FarmManager.h"

class GameInteractiveFrame : public AbstractFrame
{
public:
    GameInteractiveFrame(QMap<SocketIO*, BotData> *connectionsData, InteractionManager *interactionManager, FarmManager *farmManager);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);

private:
    InteractionManager *m_interactionManager;
    FarmManager *m_farmManager;
};

#endif // GAMEINTERACTIVEFRAME_H
