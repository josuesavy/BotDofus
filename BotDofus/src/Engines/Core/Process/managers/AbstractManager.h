#ifndef ABSTRACTMODULE_H
#define ABSTRACTMODULE_H

#include "src/Engines/Storage/DataHandler.h"

/*!
 * \brief The AbstractModule class
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

private:
    ModuleType m_type;
};
#endif // ABSTRACTMODULE_H
