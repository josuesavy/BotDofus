#ifndef EXCHANGEMODULE_H
#define EXCHANGEMODULE_H

/*!
 * \class The ExchangeModule class handle the character's exchanges with other players. Used for add, edit or delete items in a exchange.
 * \brief Module to handle character's exchanges
 * \author AnonymHax & G0hu
 * \version Beta
 */

#include "src/Engines/Core/Process/abstract/AbstractModule.h"

class ExchangeModule : public AbstractModule
{
public:
    ExchangeModule(QMap<SocketIO*, BotData> *connectionsData);

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
     * \brief Set the character's state for to know if he is in exchange or not
     * \param sender Bot's particular connection
     * \param state In exchange or not
     */
    void setState(SocketIO *sender, bool state);


    /*!
     * \brief Check if the character is in actually exchange
     * \param sender Bot's particular connection
     * \return bool In exchanging or not
     */
    bool isActive(SocketIO *sender) const;


    /*!
     * \brief Add a item in the exchange
     * \param sender Bot's particular connection
     * \param item Item to add
     */
    void addRequestedObject(SocketIO *sender, const RequestTradeObject &item);


    /*!
     * \brief Remove a item in the exchange
     * \param sender Bot's particular connection
     * \param objectGID Item's idendity to remove
     */
    void removeRequestedObject(SocketIO *sender, uint objectGID);



private:

    /*!
     * \brief Update all exchange's informations
     * \param sender Bot's particular connection
     */
    void updateExchange(SocketIO *sender);
};

#endif // EXCHANGEMODULE_H
