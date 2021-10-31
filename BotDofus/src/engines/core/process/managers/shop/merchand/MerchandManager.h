#ifndef MERCHANDMANAGER_H
#define MERCHANDMANAGER_H

/*!
 * \class The MerchandManager class for all sell and buy
 * \brief ..
 * \author Garten
 * \version Alpha
 */

#include "src/engines/core/process/managers/AbstractManager.h"

class MerchandManager : public AbstractManager
{
    Q_OBJECT
public:
    MerchandManager(QMap<SocketIO*, BotData> *connectionsData);

    virtual void reset(SocketIO *sender);

    /**
     * @brief processMerchand
     * @param sender Pointer to the bot instance
     * @return bool The character is ready or not
     */
    bool processMerchand(SocketIO *sender);

    /**
     * @brief addObjectItemToSell
     * @param sender Pointer to the bot instance
     * @param objectItemToSell Object item to add
     *
     * Add object item to sell from main inventory to merchand inventory.
     * If the item already exist in merchand inventory, it will edited.
     */
    void addObjectItemToSell(SocketIO *sender, ObjectItemToSell objectItemToSell);

    /**
     * @brief editObjectItemToSell
     * @param sender Pointer to the bot instance
     * @param objectItemToSell Object item to edit
     *
     * Edit object item to sell in merchand inventory.
     */
    void editObjectItemToSell(SocketIO *sender, ObjectItemToSell objectItemToSell);

    /**
     * @brief removeObjectItemToSell
     * @param sender Pointer to the bot instance
     * @param objectItemToSell Object item to remove
     *
     * Remove object item to sell in merchand inventory.
     */
    void removeObjectItemToSell(SocketIO *sender, ObjectItemToSell objectItemToSell);

    /**
     * @brief openMerchantWithPlayer
     * @param sender Pointer to the bot instance
     * @param merchantName The name of merchant player
     *
     * Start the exchange with a merchant player in the map
     */
    void openMerchantWithPlayer(SocketIO *sender, QString merchantName);

    /**
     * @brief buyItemFromMerchant
     * @param sender Pointer to the bot instance
     * @param objectToBuyId The object's identity
     * @param quantity The object's quantity
     *
     * Buy the item to the merchant previously selected player.
     */
    void buyItemFromMerchant(SocketIO *sender, uint objectToBuyId, uint quantity);
};

#endif // MERCHANDMANAGER_H
