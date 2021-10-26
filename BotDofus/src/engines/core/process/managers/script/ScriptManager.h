#ifndef SCRIPTMANAGER_H
#define SCRIPTMANAGER_H

/*!
  * \class ScriptManager
  * \brief Manager to regulate paths
  * \author AnonymHax & G0hu
  * \version Beta
  *
  * This Manager is used to handle paths that are loaded to the bot. The file will be parsed here and then saved to
  * what the bot should do when he enters a new map.
  */

extern "C"
{
#include "include/lua-5.4.2_Win32_dll16_lib/include/lua.h"
#include "include/lua-5.4.2_Win32_dll16_lib/include/lauxlib.h"
#include "include/lua-5.4.2_Win32_dll16_lib/include/lualib.h"
}

#ifdef _WIN32
#pragma comment(lib, "include/lua-5.4.2_Win32_dll16_lib/lua5.1.lib")
#endif

#include "src/engines/core/process/managers/script/LuaFunctions.h"

#include "src/engines/core/process/managers/map/MapManager.h"
#include "src/engines/core/process/managers/farm/FarmManager.h"
#include "src/engines/core/process/managers/fight/FightManager.h"
#include "src/engines/core/process/managers/craft/CraftManager.h"
#include "src/engines/core/process/managers/stats/StatsManager.h"
#include "src/engines/core/process/managers/interaction/InteractionManager.h"
#include "src/engines/core/process/managers/group/GroupManager.h"
#include "src/engines/core/process/managers/connection/ConnectionManager.h"
#include "src/engines/pathfinding/world/PathfindingMap.h"

#include <QString>
#include <QStringList>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

#define MOVE_MAXTIME 60000
#define FARM_MAXTIME 60000
#define CRAFT_MAXTIME 60000
#define INTERACTION_MAXTIME 60000

class ScriptManager : public AbstractManager
{
    Q_OBJECT

public:
    /*!
     * \brief ScriptManager
     * \param connectionsData
     * \param mapManager
     * \param fightManager
     * \param farmManager
     * \param craftManager
     * \param interactionManager
     * \param groupManager
     */
    ScriptManager(QMap<SocketIO*, BotData> *connectionsData, MapManager *mapManager,
                 FightManager *fightManager,
                 FarmManager *farmManager, CraftManager *craftManager,
                 InteractionManager *interactionManager,
                 GroupManager *groupManager,
                 StatsManager *statsManager,
                 ConnectionManager *connectionManager);


    virtual void reset(SocketIO *sender);
    /*!
     * \brief processMessage
     * \param data Content of the packet
     * \param sender Pointer to the bot instance
     * \return bool Returns true if the message was detected and false if not
     *
     * Base function of each Manager that is made of a switch to process each packets that will be useful for this Manager.
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);

    /*!
     * \brief parse
     * \param sender Pointer to the bot instance
     * \return int Returns 0 if no error and the line number if there is a syntax error
     *
     * Function used to parse the file loaded through the GUI by the user
     */
    int parse(SocketIO *sender);

    /*!
     * \brief unloadFile
     * \param sender Pointer to the bot instance
     *
     * Function used to clear bot informations of the path and unload script.
     */
    void unloadFile(SocketIO *sender);

    /*!
     * \brief loadFile
     * \param sender Pointer to the bot instance
     * \param p Path to the file to load
     * \return bool Returns true if the file was opened successfully.
     *
     * Function used to parse file with the path provided.
     */
    bool loadFile(SocketIO *sender, QString p);

    /*!
     * \brief setActivePath
     * \param sender Pointer to the bot instance
     * \param active Toggle activity of path
     */
    void setActivePath(SocketIO *sender, bool active);

    void setPodsLimit(SocketIO *sender, ushort ratio);

private slots:
    void cancelProcessingAction(SocketIO *sender);
    void processRepeatAction(SocketIO *sender);
    void processNextAction(SocketIO *sender);
    void processControl(SocketIO *sender);
    void waitForInactivity();

private:
    void getSettings(SocketIO *sender, lua_State *lua);
    void getGlobalFunction(SocketIO *sender, lua_State *lua, ScriptTag function);
    void getActions(SocketIO *sender, lua_State *lua);

    bool groupNeedsHeal(SocketIO *sender);
    bool groupNeedsToGoToBank(SocketIO *sender);

    QList<MapSide> getSides(QString side);
    int getMap(SocketIO *sender, QString map);

    MapManager *m_mapManager;
    FarmManager *m_farmManager;
    CraftManager *m_craftManager;
    FightManager *m_fightManager;
    QList<SocketIO*> m_waitingList;
    InteractionManager *m_interactionManager;
    GroupManager *m_groupManager;
    StatsManager *m_statsManager;
    ConnectionManager *m_connectionManager;

    lua_State *lua;
};

#endif // SCRIPTMANAGER_H
