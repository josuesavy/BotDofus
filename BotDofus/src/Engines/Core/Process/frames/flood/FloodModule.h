#ifndef FLOODMODULE_H
#define FLOODMODULE_H

/*!
 * \class FloodModule
 * \brief Module that handles flood on different channels in the same time. Also used to manage intelligent PM and flood through a mini script file.
 * \author AnonymHax & G0hu
 * \version Beta
 */

#include "src/Engines/Core/Process/Frames/AbstractFrame.h"
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

class FloodModule : public AbstractFrame
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
    void initFlood(SocketIO *sender, const QList<Channel> &channels);

    /*!
     * \brief Adds a channel in the channel list to flood of the specified bot.
     * \param sender Bot's particular connection
     * \param channel Channel to add
     */
    void addFloodChannel(SocketIO* sender, const Channel &channel);

    /*!
     * \brief Removes a channel from the channel list to flood of the specified bot.
     * \param sender Bot's particular connection
     * \param channel Channel to remove
     */
    void removeFloodChannel(SocketIO* sender, const Channel &channel);

    /*!
     * \brief Updates the message flooded by the specified bot.
     * \param sender Bot's particular connection
     * \param message New message to FloodData
     */
    void modifyFloodMessage(SocketIO* sender, const QString &message);

    /*!
     * \brief Attemps to load a list of message to flood for the specified bot.
     * Returns true if the message where successfully loaded, false if not.
     * The message to flood will automatically go to the next one when the timer is elapsed.
     * \param sender Bot's particular connection
     * \param messages List of message to flood
     * \return bool Returns true if the message where successfully loaded, false if not
     */
    bool loadMessagesFromFile(SocketIO* sender, const QStringList messages);

    /*!
     * \brief Toggles flood from file.
     * \param sender Bot's particular connection
     * \param isUsingFile Set to true to activate and false to disable
     */
    void setIsUsingFile(SocketIO* sender, const bool isUsingFile);

    /*!
     * \brief Attemps to define the message rotation cooldown when using a list of predefined message loaded through a flood file.
     * \param sender Bot's particular connection
     * \param timer Cooldown to change flood message
     * \return bool Returns true if the timer was set correctly, false if NotificationByServerMessage
     */
    bool loadTimerFromFile(SocketIO* sender, const uint timer);

    /*!
     * \brief Sets the content of the flood file when user loads a file to define
     * a set of predefined messages to flood with a rotation timer.
     * \param sender Bot's particular connection
     * \param content Content of the file
     */
    void setFileContent(SocketIO *sender, QByteArray content);

    /*!
     * \brief Gets the loaded flood file content that was previously loaded by the user.
     * \param sender Bot's particular connection
     * \return QByteArray File content
     */
    QByteArray getFileContent(SocketIO *sender);

    /*!
     * \brief Checks if the specified bot uses a flood file. Returns true if the bot is using it, false if not.
     * \param sender Bot's particular connection
     * \return bool Returns true if user is using flood file, false if not
     */
    bool getIsUsingFile(SocketIO *sender);

private slots:
    /*!
     * \brief Event for I don't know bro really
     */
    void changeFloodMessage();

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
