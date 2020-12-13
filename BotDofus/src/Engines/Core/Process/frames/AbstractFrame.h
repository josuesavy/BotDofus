#ifndef ABSTRACTFRAME_H
#define ABSTRACTFRAME_H

#include "src/engines/DataHandler.h"

/*!
 * \brief The AbstractFrame class
 */
class AbstractFrame : public QObject, public DataHandler
{
    Q_OBJECT

public:
    AbstractFrame(QMap<SocketIO*, BotData> *connectionsData);
    virtual ~AbstractFrame();

    /*!
     * \brief Process message
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender) = 0;

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
#endif // ABSTRACTFRAME_H
