#ifndef INTERACTIONMANAGER_H
#define INTERACTIONMANAGER_H

#include "src/engines/core/process/managers/AbstractManager.h"
#include "src/engines/core/process/managers/map/MapManager.h"

class InteractionManager : public AbstractManager
{
    Q_OBJECT

public:
    InteractionManager(QMap<SocketIO*, BotData> *connectionsData, MapManager *mapManager);
    ~InteractionManager();

    /*!
     * \brief Reset the module
     * \param sender Bot's particular connection
     */
    virtual void reset(SocketIO *sender);

    /*!
     * \brief Use a zaap on a map
     * \param sender Bot's particular connection
     * \param mapId The map that contain the zaap
     * \return bool Zaap has been used
     */
    bool processZaap(SocketIO *sender, int mapId);

    /*!
     * \brief Use a zaapi on a map
     * \param sender Bot's particular connection
     * \param mapID The map that contain the zaapi
     * \return bool Zaapi has been used
     */
    bool processZaapi(SocketIO *sender, int mapId);

    /*!
     * \brief Start a conversation with a NPC
     * \param sender Bot's particular connection
     * \param cellId The cell's identify where the NPC is
     * \return bool Conversation is started
     */
    bool processNpcInteraction(SocketIO *sender, int cellId);

    /*!
     * \brief Answer the NPC with a dialog
     * \param sender Bot's particular connection
     * \param dialog The dialog to send to NPC
     * \return bool The answer has been send to NPC
     */
    bool processNpcDialog(SocketIO *sender, QString dialog);

    /*!
     * \brief Close dialog with a NPC
     * \param sender Bot's particular connection
     */
    bool leaveNpcDialog(SocketIO* sender);

    /*!
     * \brief processUse
     * \param sender Bot's particular connection
     * \param id The identify of the things to use
     * \param action
     * \return bool
     */
    bool processUse(SocketIO *sender, int id);

    /*!
     * \brief Clears the bank settings of the specified bot.
     * \param sender Bot's particular connection
     */
    void clearBankData(SocketIO *sender);

    /*!
     * \brief Returns the BankData of the specified bot.
     * \param sender Bot's particular connection
     * \return BankData The data bank
     */
    BankData getBankData(SocketIO *sender);

    /*!
     * \brief Adds the specified item in the list of items to retreive from the bank while the bot will be talking to the bank NPC.
     * \param sender Bot's particular connection
     * \param item BankItem to add
     */
    void addTakeBankItem(SocketIO *sender, BankItem item);

    /*!
     * \brief Adds the specified item in the list of items to deposit to the bank while the bot will be talking to the bank NPC.
     * \param sender Bot's particular connection
     * \param item BankItem to add
     */
    void addDepositBankItem(SocketIO *sender, BankItem item);

    /*!
     * \brief Removes the specified item in the list of items to retreive from the bank while the bot will be talking to the bank NPC.
     * \param sender Bot's particular connection
     * \param item BankItem to remove
     */
    void removeTakeBankItem(SocketIO *sender, BankItem item);

    /*!
     * \brief Removes the specified item in the list of items to deposit to the bank while the bot will be talking to the bank NPC.
     * \param sender Bot's particular connection
     * \param item BankItem to remove
     */
    void removeDepositBankItem(SocketIO *sender, BankItem item);

    /*!
     * \brief Updates the quantity of item with the corresponding ID that the bot should retreive from the bank. The quantity
     * of this item to take in the inventory is the specified percentage (parameter "pods") of the pods left in the bot
     * inventory. e.g: if the bot has 100 pods left and the paramter pods has a value of 50, the bot will take a quantity
     * 50% of 100 (= 50) items with the corresponding id.
     * \param sender Bot's particular connection
     * \param itemId Item ID to update
     * \param pods Pods to update for the item with the specified ID
     */
    void updateTakeBankItem(SocketIO *sender, uint itemId, uint pods);

    /*!
     * \brief Updates the quantity of item with the corresponding ID that the bot should dropped to the bank. The quantity
     * of this item to deposit in the bank is the specified percentage (parameter "pods") of the quantity of this itme
     * that the bot has in it's inventoy. e.g: if the bot has 100 items and the paramter "pods" has a value of 50, the
     * bot will deposit a quantity 50% of 100 (= 50) items with the corresponding id.
     * \param sender Bot's particular connection
     * \param itemId Item ID to update
     * \param pods  Pods to update for the item with the specified ID
     */
    void updateDepositBankItem(SocketIO *sender, uint itemId, uint pods);

    /*!
     * \brief Sets the take condition for the sender
     * \param sender Bot's particular connection
     * \param condition The bank inclusion
     */
    void setTakeCondition(SocketIO *sender, BankInclusion condition);

    /*!
     * \brief Sets the deposit condition for the sender
     * \param sender Bot's particular connection
     * \param condition The bank inclusion
     */
    void setDepositCondition(SocketIO *sender, BankInclusion condition);

    /*!
     * \brief Allows the user to activate or disactivate the pet feeding process.
     * \param sender Bot's particular connection
     * \param toggle bool to (dis)activate pet feed
     */
    void toggleFeed(SocketIO *sender, bool toggle);

    /*!
     * \brief Sets the meal of the pets with the corresponding GID (global ID) to the food GID specified.
     * \param sender Bot's particular connection
     * \param id Pet global ID (GID)
     * \param food Food global ID (GID)
     */
    void setPetFood(SocketIO *sender, uint id, int food);

    /*!
     * \brief Sets the interval of time that the bot should wait before feeding all the pets with the corresponding GIDs.
     * \param sender Bot's particular connection
     * \param id Pet global ID
     * \param timer timer to feed pet
     */
    void setFeedTimer(SocketIO *sender, uint id, int timer);


    QString nameFromUid(SocketIO *sender, int uid);

    bool concernedByBankDeposit(SocketIO *sender, int id);

    bool concernedByBankTake(SocketIO *sender, int id);


    QList<SocketIO*> waitingReplies;
    QList<SocketIO*> finishedAction;
    QList<SocketIO*> m_confirmAction;

private slots:
    void feed();
    void finishAction();
    void confirmAction();
    void moved(SocketIO *sender);
    void noMovement(SocketIO *sender);

private:
    int getFoodUID(SocketIO *sender, int uid, int food);

    MapManager *m_mapManager;
    QMap<PetFeedInfos, SocketIO*> m_feed;
    QList< QPair<SocketIO*, PetFeedInfos> > m_connection;

};

#endif // INTERACTIONMANAGER_H
