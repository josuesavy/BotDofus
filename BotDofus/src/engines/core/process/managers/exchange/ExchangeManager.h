#ifndef EXCHANGEMANAGER_H
#define EXCHANGEMANAGER_H

#include "src/engines/core/process/managers/AbstractManager.h"

class ExchangeManager : public AbstractManager
{
public:
    ExchangeManager(QMap<SocketIO*, BotData> *connectionsData);

    /*!
     * \brief Reset the module
     * \param sender Bot's particular connection
     */
    virtual void reset(SocketIO *sender);

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


    /*!
     * \brief Update all exchange's informations
     * \param sender Bot's particular connection
     */
    void updateExchange(SocketIO *sender);
};

#endif // EXCHANGEMANAGER_H
