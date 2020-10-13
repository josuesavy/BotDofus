#ifndef STATSMODULE_H
#define STATSMODULE_H

/*!
 * \class The StatsModule class handle the characterisics, the inventory, pets and mount of the bot. Used to feed pets, use, equip and delete items from the bot's inventory. It can also be used to increase the bot's spell's level.
 * \brief Module to handle characters stats
 * \author AnonymHax & G0hu
 * \version Beta
 */

#include "src/Engines/Core/Process/abstract/AbstractModule.h"
#include "src/Engines/IO/D2O/GameDataDeclarator.h"
#include "src/Protocol/Enums/Data/ListAddFailureEnum.h"
#include "src/Protocol/Enums/Data/SubscriptionRequiredEnum.h"

struct LifeRegenQueue
{
    QTime time;
    int interval;
    QTimer *timer;
    SocketIO* sender;
};

class StatsModule : public AbstractModule
{
    Q_OBJECT

public:
    StatsModule(QMap<SocketIO*, BotData> *connectionsData);

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
     * \brief Drop the item as parameter on the ground
     * \param sender Bot's particular connection
     * \param uid Item's identity
     * \param quantity Item's quantity
     */
    void throwItem(SocketIO *sender, uint uid, uint quantity);


    /*!
     * \brief Delete from the inventory the item set as parameter
     * \param sender Bot's particular connection
     * \param id Item's identity
     * \param all If true, delete the all the quantity of the item, else delete only one item
     */
    void destroyItem(SocketIO *sender, uint uid, uint quantity);


    /*!
     * \brief Use the item set as parameter
     * \param sender Bot's particular connection
     * \param id Item's identity
     */
    void useItem(SocketIO *sender, uint uid);


    /*!
     * \brief Increase a specific stat
     * \param sender Bot's particular connection
     * \param stat Stat's spécification
     */
    void increaseStat(SocketIO *sender, PlayerD2OFields stat);

    /*!
     * \brief Reset bot's stats
     * \param sender Bot's particular connection
     */
    void resetStat(SocketIO *sender);


    /*!
     * \brief Set the ratio xp of the mount
     * \param sender Bot's particular connection
     * \param ratio Ratio of xp
     */
    void updateMountXpRatio(SocketIO *sender, uint ratio);


    /*!
     * \brief Recover the the mount's boosts
     * \param sender Bot's particular connection
     * \return QString The string of the mount's boosts
     */
    QString getMountEffects(SocketIO *sender);


    /*!
     * \brief Use a special emote to heal
     * \param sender Bot's particular connection
     * \return bool Using the emote successful
     */
    bool healSit(SocketIO* sender);


    /*!
     * \brief Use item(s) to heal until at the percentage specified
     * \param sender Bot's particular connection
     * \return bool Using the item successful
     */
    bool healEat(SocketIO* sender);


    /*!
     * \brief Request the possibity to equip an item
     * \param gid Item's identity
     * \return bool The possibility to equip the item
     */
    bool canEquipItem(uint gid);


    /*!
     * \brief Equip an item present in the inventory
     * \param sender Bot's particular connection
     * \param uid Item's identity
     */
    void equipItem(SocketIO* sender, uint uid);


    /*!
     * \brief Unequip an item already equipped
     * \param sender Bot's particular connection
     * \param uid Item's identity
     */
    void unequipItem(SocketIO *sender, uint uid);


    /*!
     * \brief Free the soul
     * \param sender Bot's particular connection
     */
    void freeSoul(SocketIO *sender);


    /*!
     * \brief Request if there is need to heal
     * \param sender Bot's particular connection
     * \return bool Need to heal
     */
    bool needsHeal(SocketIO *sender);


    /*!
     * \brief Request if there is need to go to bank
     * \param sender Bot's particular connection
     * \return bool Need to go to bank
     */
    bool needsToGoToBank(SocketIO *sender);


    /*!
     * \brief Request if there is need to go to phoenix
     * \param sender Bot's particular connection
     * \return bool Need to go to phoenix
     */
    bool needsToGoToPhoenix(SocketIO *sender);


    /*!
     * \brief Enable the heal in using an item
     * \param sender Bot's particular connection
     * \param enabled Activation
     */
    void setRegenUseObjectsEnabled(SocketIO *sender, bool enabled);


    /*!
     * \brief Set the range to heal
     * \param sender Bot's particular connection
     * \param min The minimum life
     * \param max The maximum life
     */
    void setRegenerationRatio(SocketIO *sender, uint min, uint max);


    /*!
     * \brief Change status
     * \param sender Bot's particular connection
     * \param statusId Status's identify
     * \param message The reason for the absence (optional)
     */
    void setPlayerStatusUpdate(SocketIO *sender, PlayerStatusEnum statusId, QString message = nullptr);


    /*!
     * \brief Enable the automatic acceptance achievement
     * \param sender Bot's particular connection
     * \param active Activation
     */
    void setAutomaticallyAcceptAchievement(SocketIO *sender, bool active);


    void defineSkinHead(SocketIO *sender, QPixmap pixmap);

    void quitDidactiel(SocketIO *sender);

private slots:

    /*!
     * \brief Heal's event finished
     */
    void healFinished();


    /*!
     * \brief Instant healing event
     */
    void passiveHealing();


    /*!
     * \brief Heal's event blocked
     */
    void preventRegenBlocked();



signals:

    /*!
     * \brief Signal to inform the heal are finished
     * \param sender Bot's particular connection
     */
    void healed(SocketIO* sender);



private:
    QMap<uint, QString> m_pets;
    QList<LifeRegenQueue> m_regenQueue;
    QList<LifeRegenQueue> m_passiveRegen;
    QList<LifeRegenQueue> m_preventRegenBlocked;
    QList<CharacterInventoryPositionEnum> m_inventoryPositions;

    /*!
     * \brief Regen optimizer
     * \param sender Bot's particular connection
     */
    void regenOptimizer(SocketIO *sender);

    /*!
     * \brief Update the required stats
     * \param sender Bot's particular connection
     */
    void updateRequiredStats(SocketIO *sender);
};

#endif // STATSMODULE_H
