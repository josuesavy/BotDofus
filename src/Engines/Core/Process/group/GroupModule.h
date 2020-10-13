#ifndef GROUPMODULE_H
#define GROUPMODULE_H

/*!
 * \class GroupModule
 * \brief Module that handles all the teams. Used to manage team fight paths and going to bank as a group for example
 * \author AnonymHax & G0hu
 * \version Beta
 */

#include "src/Engines/Core/Process/map/MapModule.h"

class GroupModule : public AbstractModule
{
    Q_OBJECT

public:
    /*!
     * \brief GroupModule
     * \param connectionsData
     * \param mapModule
     */
    GroupModule(QMap<SocketIO*, BotData> *connectionsData, MapModule *mapModule);

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
     * \brief Toggles the auto-follow of the specified bot's master.
     * \param sender Bot's particular connection
     * \param followUp (dis)actives auto-follow of the bot's master
     */
    void setFollowUpEnabled(SocketIO *sender, bool followUp);

    /*!
     * \brief Defines the name of the specified bot's master. Set to "" to define no master.
     * \param sender Bot's particular connection
     * \param master Name of the master
     */
    void setMaster(SocketIO *sender, const QString &master);

    /*!
     * \brief Recover the connection instance of group's master
     * \param sender Bot's particular connection
     * \return SocketIO Connection instance
     */
    SocketIO *getMaster(SocketIO *sender);

    /*!
     * \brief Recover the list of connection instance of group's slaves
     * \param sender Bot's particular connection
     * \return QList<SocketIO*> The list of group's slaves
     */
    QList<SocketIO*> getSlaves(SocketIO *sender);

    /*!
     * \brief Check if all group members are on the same map
     * \param master Bot's particular connection
     * \return bool All group member are here or not
     */
    bool isGroupOnMapAndInactive(SocketIO *master);

    /*!
     * \brief Check if all slaves are in the group
     */
    void updateTeams();

    void teleportSlavesToMaster(SocketIO *sender, const QString master);

private slots:
    /*!
     * \brief Event to update the follow up the master
     * \param sender Bot's particular connection
     */
    void followUpUpdate(SocketIO *sender);

    /*!
     * \brief Event to disabled the slave's following of master
     * \param sender Bot's particular connection
     */
    void followUpFailure(SocketIO *sender);

private:    
    MapModule *m_mapModule;
};

#endif // GROUPMODULE_H
