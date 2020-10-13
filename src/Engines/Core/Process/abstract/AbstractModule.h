#ifndef ABSTRACTMODULE_H
#define ABSTRACTMODULE_H

#include "src/Engines/Storage/DataHandler.h"

/*!
 * \brief The AbstractModule class
 */
class AbstractModule : public QObject, public DataHandler
{
    Q_OBJECT

public:
    AbstractModule(ModuleType type, QMap<SocketIO*, BotData> *connectionsData);
    virtual ~AbstractModule();

    /*!
     * \brief Reset the module
     * \param sender Bot's particular connection
     */
    virtual void reset(SocketIO *sender) = 0;

    /*!
     * \brief Process message
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender) = 0;

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
