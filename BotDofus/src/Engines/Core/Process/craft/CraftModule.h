#ifndef CRAFTMODULE_H
#define CRAFTMODULE_H

/*!
 * \class The CraftModule class handle the recipe's creation, check the posibilities to make a recipe, compare two recipes and use a craft machine.
 * \brief Module to handle characters craft
 * \author AnonymHax & G0hu
 * \version Beta
 */

#include "src/Engines/Core/Process/map/MapModule.h"
#include "src/Engines/Core/Process/abstract/AbstractFrame.h"

class CraftModule : public AbstractFrame
{
    Q_OBJECT

public:
    CraftModule(QMap<SocketIO*, BotData> *connectionsData, MapModule *mapModule);


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
     * \brief Check if the character is ready to craft and start the craft
     * \param sender Bot's particular connection
     * \return bool The character is ready or not
     */
    bool processCraft(SocketIO *sender);


    /*!
     * \brief Start the bot's craft
     * \param sender Bot's particular connection
     */
    void processCrafting(SocketIO *sender);


    /*!
     * \brief Fill the recipe's list from the character's inventory for his craft
     * \param sender Bot's particular connection
     */
    void processCraftQuantities(SocketIO *sender);


    /*!
     * \brief Return all character's craft recipes name
     * \return QMap<QString, uint> Craft's dictionnary (Name's recipe, id's recipe)
     */
    QMap<QString, uint> getRecipesName() const;


    /*!
     * \brief Return character's craft list
     * \param sender Bot's particular connection
     * \return QList<uint> Identify's each recipes
     */
    QList<uint> getCraftList(SocketIO *sender) const;


    /*!
     * \brief Add the character's inventory item in the character's craft list
     * \param sender Bot's particular connection
     * \param craft Name's craft
     */
    void addItemToCraftList(SocketIO *sender, QString craft);


    /*!
     * \brief Remove a item in the craft list
     * \param sender Bot's particular connection
     * \param index Craft's identify of the list
     */
    void removeItemOfCraftList(SocketIO *sender, uint index);


    /*!
     * \brief Update item's quantity in the craft list
     * \param sender Bot's particular connection
     * \param index Craft's identify of the list
     * \param quantity Quantity
     */
    void updateQuantity(SocketIO *sender, uint index, int quantity);



private slots:

    /*!
     * \brief Event to update and inform the craft is finished
     * \param sender Bot's particular connection
     */
    void couldNotMove(SocketIO *sender);


    /*!
     * \brief Use a craft's machine in the workshop
     * \param sender Bot's particular connection
     */
    void useCraftingBench(SocketIO *sender);



private:

    /*!
     * \brief Add craft component's quantity
     * \param sender Bot's particular connection
     * \param o The craft component
     */
    void addCraftComponent(SocketIO *sender, QSharedPointer<ObjectItem> o);


    /*!
     * \brief Check if both recipe have one difference
     * \param left The first recipe
     * \param right The second recipe
     * \return bool Have one diffrence
     */
    bool compareRecipes(QMap<uint, uint> left, QMap<uint, uint> right);


    /*!
     * \brief removeFromInventory
     * \param inventory
     * \param recipe
     */
    void removeFromInventory(QList<InventoryObject> &inventory, RecipeInfos recipe);


    /*!
     * \brief Check if it's possible to make the recipe
     * \param sender Bot's particular connection
     * \param inventory The list of items in the inventory
     * \param recipe The recipe as want make
     * \return bool Possibilities
     */
    bool canCraftItem(SocketIO *sender, QList<InventoryObject> inventory, RecipeInfos recipe);

    MapModule *m_mapModule;
    QMap<QString, uint> m_recipesName;
    QMap<uint, RecipeInfos> m_recipes;
};

#endif // CRAFTMODULE_H
