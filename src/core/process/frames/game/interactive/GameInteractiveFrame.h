#ifndef GAMEINTERACTIVEFRAME_H
#define GAMEINTERACTIVEFRAME_H

#include "src/core/process/frames/AbstractFrame.h"
#include "src/core/process/managers/interaction/InteractionManager.h"
#include "src/core/process/managers/farm/FarmManager.h"
#include "src/io/d2p/map/elements/GraphicalElement.h"

class GameInteractiveFrame : public AbstractFrame
{
    Q_OBJECT

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
