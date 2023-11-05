#ifndef SHOPMODULE_H
#define SHOPMODULE_H

/*!
 * \class The ShopModule class for all sell and buy
 * \brief ..
 * \author Garten
 * \version Alpha
 */

#include "src/core/process/frames/AbstractFrame.h"

enum class QuantityEnum
{
    QUANTITY_1,
    QUANTITY_10,
    QUANTITY_100
};

class ShopModule : public AbstractFrame
{
    Q_OBJECT
public:
    ShopModule(QMap<SocketIO*, BotData> *connectionsData);


    virtual void reset(SocketIO *sender);

    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);

    bool processMerchand(SocketIO *sender);

    bool processShop(SocketIO *sender);

    void buyItem(SocketIO *sender, uint genid);

    void addItemToSell(SocketIO *sender, uint item, int quantity, double price);

    bool getIsItemExistInMerchand(SocketIO *sender, uint objectGID);
};

#endif // SHOPMODULE_H


//Lancer
//[SND] > InteractiveUseRequestMessage
//[RCV] InteractiveUsedMessage
//[RCV] ExchangeStartedBidBuyerMessage (Filtres : Aile, Bois, Clef, etc..)

//Acheter
//[SND] > ExchangeBidHouseTypeMessage (Follow : Aile, Bois, Clef, etc..)
//[RCV] ExchangeTypesExchangerDescriptionForUserMessage (Liste des items en vente)
//[SND] > ExchangeBidHouseSearchMessage (Follow item dans la liste)
//[RCV] ExchangeTypesItemsExchangerDescriptionForUserMessage (Informations sur l'item, Price : 1, 10, 100)
//[SND] > ExchangeBidHouseBuyMessage
//[RCV] ExchangeBidHouseBuyResultMessage


//Vendre
//[SND] > NpcGenericActionRequestMessage
//[RCV] ExchangeLeaveMessage
//[RCV] ExchangeStartedBidSellerMessage (Filtres : Aile, Bois, Clef, etc..)
//[SND] > ExchangeBidHouseSearchMessage (Follow item dans l'inventaire)
//[RCV] ExchangeTypesItemsExchangerDescriptionForUserMessage (Informations sur l'item, Price : 1, 10, 100)
//[SND] > ExchangeBidHousePriceMessage (Follow item dans l'inventaire)
//[RCV] ExchangeBidPriceForSellerMessage
//[SND] > ExchangeObjectMovePricedMessage (Price, object's id, quantity)
//[RCV] ExchangeBidHouseItemAddOkMessage (informations sur l'item mis en vente)
//[RCV] ExchangeBidHouseInListUpdatedMessage (update new item put in sell)
//[SND] > ExchangeBidHousePriceMessage (Follow item dans l'inventaire)
//[RCV] ExchangeBidPriceForSellerMessage

//Quitter
//[SND] > LeaveDialogRequestMessage
//[RCV] ExchangeLeaveMessage
