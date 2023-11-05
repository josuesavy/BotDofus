#ifndef ABSTRACTMANAGER_H
#define ABSTRACTMANAGER_H

#include "src/core/DataHandler.h"

/*!
 * \brief The AbstractManager class
 */
class AbstractManager : public QObject, public DataHandler
{
    Q_OBJECT

public:
    AbstractManager(ManagerType type, QMap<SocketIO*, BotData> *connectionsData);
    virtual ~AbstractManager();

    /*!
     * \brief Reset the module
     * \param sender Bot's particular connection
     */
    virtual void reset(SocketIO *sender) = 0;

    /*!
     * \brief Get type of module in progress
     * \return The module type in progress
     */
    ManagerType getType();

signals:
    void requestUpdate(SocketIO *sender);
    void scriptActionDone(SocketIO *sender);
    void scriptActionRepeat(SocketIO *sender);
    void scriptActionCancel(SocketIO *sender);
    void scriptActionFailure(SocketIO *sender);
    void requestResetData(SocketIO *sender);

private:
    ManagerType m_type;
};
#endif // ABSTRACTMANAGER_H
