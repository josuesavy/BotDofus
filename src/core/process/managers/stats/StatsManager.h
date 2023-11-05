#ifndef STATSMANAGER_H
#define STATSMANAGER_H

#include "src/core/process/managers/AbstractManager.h"

struct LifeRegenQueue
{
    QElapsedTimer time;
    int interval;
    QTimer *timer;
    SocketIO* sender;
};

bool operator==(const LifeRegenQueue &left, const LifeRegenQueue &right);

class StatsManager : public AbstractManager
{
    Q_OBJECT

public:
    StatsManager(QMap<SocketIO*, BotData> *connectionsData);

    /*!
     * \brief Reset the module
     * \param sender Bot's particular connection
     */
    virtual void reset(SocketIO *sender);

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


    /*!
     * \brief Send a message to give up didactiel
     * \param sender Bot's particular connection
     */
    void quitDidactiel(SocketIO *sender);

    const QMap<uint, QString> &getPets();
    void setPets(const QMap<uint, QString> &pets);

    const QList<LifeRegenQueue> &getRegenQueue();
    void setRegenQueue(const QList<LifeRegenQueue> &regenQueue);
    void setRegenQueue(LifeRegenQueue item);

    QList<LifeRegenQueue> &getPassiveRegen();
    void setPassiveRegen(const QList<LifeRegenQueue> &passiveRegen);
    void setPassiveRegen(LifeRegenQueue item);

    const QList<LifeRegenQueue> &getPreventRegenBlocked();
    void setPreventRegenBlocked(const QList<LifeRegenQueue> &preventRegenBlocked);

    const QList<CharacterInventoryPositionEnum> &getInventoryPositions();

    void defineUrlHead(SocketIO *sender, QUrl url);
    void defineUrlFull(SocketIO *sender, QUrl url);
    void defineSkinHead(SocketIO *sender, QPixmap pixmap);
    void defineSkinFull(SocketIO *sender, QPixmap pixmap);

    int getHealthPoints(SocketIO* sender);
    int getMaxHealthPoints(SocketIO* sender);

public slots:

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
};

#endif // STATSMANAGER_H
