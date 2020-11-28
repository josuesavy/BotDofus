#ifndef FARMMANAGER_H
#define FARMMANAGER_H

#include "src/Engines/Core/Process/managers/AbstractManager.h"
#include "src/Engines/Core/Process/Managers/map/MapManager.h"

class FarmManager : public AbstractManager
{
    Q_OBJECT

public:
    FarmManager(QMap<SocketIO*, BotData> *connectionsData, MapManager *mapManager);

    /*!
     * \brief Reset the module
     * \param sender Bot's particular connection
     */
    virtual void reset(SocketIO *sender);

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



public slots:
    /*!
     * \brief Check the character's position and direction on the map to farm a resource
     * \param sender Bot's particular connection
     */
    void farmAction(SocketIO *sender);



private slots:

    /*!
     * \brief Event when the character farm a resource
     * \param sender Bot's particular connection
     */
    void activateSkill(SocketIO *sender);



private:
    MapManager *m_mapManager;
    QMap<QString, UsableItem> m_items;
};

#endif // FARMMANAGER_H
