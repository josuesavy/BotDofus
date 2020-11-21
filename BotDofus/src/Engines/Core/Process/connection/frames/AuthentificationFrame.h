#ifndef AUTHENTIFICATIONFRAME_H
#define AUTHENTIFICATIONFRAME_H


#include <QInputDialog>
#include <QtSql/QtSql>

#include "src/Engines/Core/Process/abstract/AbstractFrame.h"
#include "src/Engines/Core/Process/connection/managers/ConnectionManager.h"

enum class DofusVersion
{
    MAJOR = 2,
    MINOR = 57,
    CODE = 9,
    BUILD = 13,
};

class AuthentificationFrame : public AbstractFrame
{
public:
    AuthentificationFrame(QMap<SocketIO*, BotData> *connectionsData);

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

#endif // AUTHENTIFICATIONFRAME_H
