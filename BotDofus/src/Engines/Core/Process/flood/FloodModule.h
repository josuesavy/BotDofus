#ifndef FLOODMODULE_H
#define FLOODMODULE_H

/*!
 * \class FloodModule
 * \brief Module that handles flood on different channels in the same time. Also used to manage intelligent PM and flood through a mini script file.
 * \author AnonymHax & G0hu
 * \version Beta
 */

#include "src/Engines/Core/Process/abstract/AbstractModule.h"
#include <QPropertyAnimation>
//#include "src/network/CleverBot.h"

/*!
 * \struct FloodRequest
 * \brief The FloodRequest struct
 *
 * Holds all the informations that are required for a bot to flood properly: pointer to bot instance, Channel, timer
 * and time cooldown between two messages.
 */
struct FloodRequest
{
    SocketIO* sender;   /*!< Pointer to the bot instance */
    Channel channel;    /*!< Channel to flood on */
    QString message;
    QTime elapsedTime;  /*!< Timer of elapsed time since the last message sent */
    int estimatedTime;  /*!< Cooldown between two messages */
};

/*!
 * \brief operator <
 * \param left
 * \param right
 * \return bool
 */
bool operator<(const FloodRequest &left, const FloodRequest &right);

/*!
 * \brief operator !=
 * \param left
 * \param right
 * \return bool
 */
bool operator!=(const FloodRequest &left, const FloodRequest &right);

/*!
 * \brief operator ==
 * \param left
 * \param right
 * \return bool
 */
bool operator==(const FloodRequest &left, const FloodRequest &right);

class FloodModule : public AbstractModule
{

    Q_OBJECT

public:
    /*!
     * \brief FloodModule
     * \param connectionsData
     */
    FloodModule(QMap<SocketIO*, BotData> *connectionsData);
    ~FloodModule();

    /*!
     * \brief Reset the module
     * \param sender Bot's particular connection
     */
    virtual void reset(SocketIO *sender);

    /*!
     * \brief Process message of the stats
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);

    /*!
     * \brief Defines the range of player levels to flood in PM for the specified bot.
     * \param sender Bot's particular connection
     * \param min Minimum receiver level to flood in PM
     * \param max Maximum receiver level to flood in PM
     */
    void setFloodLevels(SocketIO *sender, int min, int max);

    /*!
     * \brief Sends the message in the specified channel with the specified bot.
     * \param sender Bot's particular connection
     * \param messageContent Message to send
     * \param channel Channel in which to send the message
     */
    void sendChatMessage(SocketIO *sender, const QString &messageContent, const Channel &channel);

    /*!
     * \brief Attemps to send a PM to the corresponding receiver with the specified message from the specified bot.
     * \param sender Bot's particular connection
     * \param messageContent Message to send
     * \param receiver Name of the PM receiver
     */
    void sendChatMessage(SocketIO *sender, const QString &messageContent, const QString &receiver);

    /*!
     * \brief Sends the smileys
     * \param send Bot's particular connection
     * \param smileyId Id smiley for send
     */
    void sendChatSmiley(SocketIO *sender, uint smileyId); // ADD

    /*!
     * \brief Toggles of the flood.
     * \param sender Bot's particular connection
     */
    void endFlood(SocketIO *sender);

    /*!
     * \brief Sets the channels in which the specified bot has to flood.
     * \param sender Bot's particular connection
     * \param channels List of channels in which to flood
     */
    void initFlood(SocketIO *sender, const QList<FloodMessage> &floods);

    /*!
     * \brief Adds a channel in the channel list to flood of the specified bot.
     * \param sender Bot's particular connection
     * \param channel Channel to add
     */
    void addFloodChannel(SocketIO* sender, const FloodMessage &flood);

    /*!
     * \brief Removes a channel from the channel list to flood of the specified bot.
     * \param sender Bot's particular connection
     * \param channel Channel to remove
     */
    void removeFloodChannel(SocketIO* sender, const FloodMessage &flood);

private slots:
    /*!
     * \brief Event allow to wait before send a message
     */
    void processFloodWaiting();

private:
    /*!
     * \brief Make a random word
     * \return QString word random
     */
    QString randomizeFloodMessage();
    QList<FloodRequest> m_floodRequests;
};

#endif // FLOODMODULE_H
