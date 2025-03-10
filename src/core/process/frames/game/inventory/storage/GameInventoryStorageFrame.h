#ifndef GAMEINVENTORYSTORAGEFRAME_H
#define GAMEINVENTORYSTORAGEFRAME_H

#include "src/core/process/frames/AbstractFrame.h"
#include "src/core/process/managers/interaction/InteractionManager.h"

class GameInventoryStorageFrame : public AbstractFrame
{
public:
    GameInventoryStorageFrame(QMap<SocketIO*, BotData> *connectionsData, InteractionManager *interactionManager);

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

#endif // GAMEINVENTORYSTORAGEFRAME_H
