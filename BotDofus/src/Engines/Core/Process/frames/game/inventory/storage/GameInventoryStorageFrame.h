#ifndef GAMEINVENTORYSTORAGEFRAME_H
#define GAMEINVENTORYSTORAGEFRAME_H

#include "src/Engines/Core/Process/Frames/AbstractFrame.h"
#include "src/Engines/Core/Process/Managers/interaction/InteractionManager.h"

class GameInventoryStorageFrame : public AbstractFrame
{
public:
    GameInventoryStorageFrame(QMap<SocketIO*, BotData> *connectionsData, InteractionManager *interactionManager);

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
    InteractionManager *m_interactionManager;
};

#endif // GAMEINVENTORYSTORAGEFRAME_H
