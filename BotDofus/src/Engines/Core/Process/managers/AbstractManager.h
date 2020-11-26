#ifndef ABSTRACTMANAGER_H
#define ABSTRACTMANAGER_H

#include "src/Engines/Storage/DataHandler.h"

/*!
 * \brief The AbstractManager class
 */
class AbstractManager : public QObject, public DataHandler
{
    Q_OBJECT

public:
    AbstractManager(ModuleType type, QMap<SocketIO*, BotData> *connectionsData);
    virtual ~AbstractManager();

    /*!
     * \brief Get type of module in progress
     * \return The module type in progress
     */
    ModuleType getType();

signals:
    void requestUpdate(SocketIO *sender);
    void scriptActionDone(SocketIO *sender);
    void scriptActionRepeat(SocketIO *sender);
    void scriptActionCancel(SocketIO *sender);
    void scriptActionFailure(SocketIO *sender);
    void requestResetData(SocketIO *sender);

protected:
    QMap<SocketIO *, BotData> *m_connectionsData;

private:
    ModuleType m_type;
};
#endif // ABSTRACTMANAGER_H
