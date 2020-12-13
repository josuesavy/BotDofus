#ifndef CONNECTIONFRAME_H
#define CONNECTIONFRAME_H

#include <QInputDialog>
#include <QtSql/QtSql>

#include "src/engines/core/process/frames/AbstractFrame.h"
#include "src/engines/core/process/managers/connection/ConnectionManager.h"
#include "src/gui/main/forms/dialogs/treewidgetdialog.h"

class ConnectionFrame : public AbstractFrame
{
public:
    ConnectionFrame(QMap<SocketIO*, BotData> *connectionsData, ConnectionManager *connectionManager);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);

private:
    ConnectionManager *m_connectionManager;
};

#endif // CONNECTIONFRAME_H
