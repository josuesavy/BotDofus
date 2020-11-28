#ifndef GAMEDIALOGFRAME_H
#define GAMEDIALOGFRAME_H

#include "src/Engines/Core/Process/frames/AbstractFrame.h"
#include "src/Engines/Core/Process/Managers/interaction/InteractionManager.h"

class GameDialogFrame : public AbstractFrame
{
public:
    GameDialogFrame(QMap<SocketIO*, BotData> *connectionsData, InteractionManager *interactionManager);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);

private:
    InteractionManager *m_interactionManager;
};

#endif // GAMEDIALOGFRAME_H
