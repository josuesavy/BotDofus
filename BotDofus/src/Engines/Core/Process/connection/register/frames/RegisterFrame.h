#ifndef REGISTERFRAME_H
#define REGISTERFRAME_H

#include <QInputDialog>

#include "src/Engines/Core/Process/abstract/AbstractFrame.h"

class RegisterFrame : public AbstractFrame
{
public:
    RegisterFrame(QMap<SocketIO*, BotData> *connectionsData);

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
};

#endif // REGISTERFRAME_H
