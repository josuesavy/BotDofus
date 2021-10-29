#ifndef SHOPMANAGER_H
#define SHOPMANAGER_H

/*!
 * \class The ShopManager class for all sell and buy
 * \brief ..
 * \author Garten
 * \version Alpha
 */

#include "src/engines/core/process/managers/AbstractManager.h"

enum class QuantityEnum
{
    QUANTITY_1,
    QUANTITY_10,
    QUANTITY_100
};

class ShopManager : public AbstractManager
{
    Q_OBJECT
public:
    ShopManager(QMap<SocketIO*, BotData> *connectionsData);

    virtual void reset(SocketIO *sender);


    bool processMerchand(SocketIO *sender);

    bool processShop(SocketIO *sender);

    void buyItem(SocketIO *sender, uint genid);

    void addItemToSell(SocketIO *sender, uint item, int quantity, double price);

    bool getIsItemExistInMerchand(SocketIO *sender, uint objectGID);
};

#endif // SHOPMANAGER_H
