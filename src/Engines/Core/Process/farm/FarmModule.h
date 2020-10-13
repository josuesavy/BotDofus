#ifndef FarmModule_H
#define FarmModule_H

/*!
 * \class The FarmModule class handle the farm of resources on the map. Used to check if it's possible to farm on the map, edit auto delete of the resources's list to farm, edit the resources's list to farm.
 * \brief Module to handle the farm resources
 * \author AnonymHax & G0hu
 * \version Beta
 */

#include "src/Engines/Core/Process/map/MapModule.h"
#include "src/Engines/Pathfinding/Map/Pathfinding.h"

class FarmModule : public AbstractModule
{
    Q_OBJECT

public:
    FarmModule(QMap<SocketIO*, BotData> *connectionsData, MapModule *mapModule);


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
     * \brief Check if a interactive element can be farm by the character
     * \param element The interactive element to check
     * \return static bool Possibility to farm
     */
    static bool canFarmResource(InteractiveElementInfos element);


    /*!
     * \brief Initilialize the character's farming on the map and return if he is in farming
     * \param sender Bot's particular connection
     * \return bool Character is in farming
     */
    bool processFarm(SocketIO *sender);


    /*!
     * \brief Clear the character's auto delete list
     * \param sender Bot's particular connection
     */
    void clearAutoDeleteList(SocketIO *sender);


    /*!
     * \brief Check if the character's resources list is empty
     * \param sender Bot's particular connection
     * \return bool Empty or not
     */
    bool resourcesListIsEmpty(SocketIO *sender);


    /*!
     * \brief Add a ressource to delete
     * \param sender Bot's particular connection
     * \param name The resource's name to add
     */
    void addResourceToDelete(SocketIO *sender, QString name);


    /*!
     * \brief Add or edit a resource to farm in the list
     * \param sender Bot's particular connection
     * \param id The item's identify to edit or add
     * \param add Add or delete the resource
     * \return bool The resources list is empty or not
     */
    bool editResourcesList(SocketIO *sender, uint id, bool add);


    /*!
     * \brief Remove a item in the resource list to delete
     * \param sender Bot's particular connection
     * \param name The resource's name
     */
    void removeResourceToDelete(SocketIO *sender, QString name);



    /*!
     * \brief Recover a item by his name
     * \param name The resource's name
     * \return uint The item's identify
     */
    uint getItemId(QString name);


    /*!
     * \brief Recover the job by his identify
     * \param jobId The job's identify
     * \return QString The job's name
     */
    QString getJobName(uint jobId);


    /*!
     * \brief Check if the item is usable
     * \param name The item's name
     * \return bool Usable or not
     */
    bool isItemUsable(QString name);


    /*!
     * \brief Recover all resource's name of a job
     * \param job The job
     * \return QStringList Resource's names list
     */
    QStringList getResourcesName(Jobs job);

    bool variantLessThan(const InteractiveElementAction &v1, const InteractiveElementAction &v2);



private slots:

    /*!
     * \brief Event when the character farm a resource
     * \param sender Bot's particular connection
     */
    void activateSkill(SocketIO *sender);


    /*!
     * \brief Check the character's position and direction on the map to farm a resource
     * \param sender Bot's particular connection
     */
    void farmAction(SocketIO *sender);



private:
    MapModule *m_mapModule;
    QMap<QString, UsableItem> m_items;
};

#endif // FarmModule_H
