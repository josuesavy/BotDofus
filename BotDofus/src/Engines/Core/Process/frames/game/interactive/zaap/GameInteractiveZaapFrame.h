#ifndef GAMEINTERACTIVEZAAPFRAME_H
#define GAMEINTERACTIVEZAAPFRAME_H

#include "src/engines/core/process/frames/AbstractFrame.h"
#include "src/engines/core/process/managers/interaction/InteractionManager.h"

class GameInteractiveZaapFrame : public AbstractFrame
{
public:
    GameInteractiveZaapFrame(QMap<SocketIO*, BotData> *connectionsData, InteractionManager *interactionManager);

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

#endif // GAMEINTERACTIVEZAAPFRAME_H
