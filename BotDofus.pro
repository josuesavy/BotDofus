#-------------------------------------------------
#
# Project created by AnonymHax 2013-11-24T00:49:43
# Project revised by Garten 2019-05-02T23:47:27
#
#-------------------------------------------------

# Specifies the Qt modules that are used by your project.
QT += core
QT += gui
QT += network
QT += quickwidgets
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Specifies project configuration and compiler options.
CONFIG += c++11

# SOFTWARE'S INFORMATIONS
# Specifies the name of the target file.
TARGET = BotDofus
# Specifies the version number of the application (major.minor.patch.build)
VERSION = 0.1.0.0
# Specifies the name of the template to use when generating the project.
TEMPLATE = app

# Declaring other libraries
win32: {
    #LIBS += -L$$PWD/lib/zlib -lzlib -lzdll
    LIBS += $$PWD/bin/zlib1.dll
    LIBS += -L$$PWD/lib/openssl -llibeay32 -lssleay32
    LIBS += -L$$PWD/lib/curl -llibcurl
}
#macx:LIBS += -L$$PWD/lib/zlib -lzlib -lzdll
#unix:LIBS += -L$$PWD/lib/zlib -lzlib -lzdll

# Specifies the #include directories which should be searched when compiling the project.
INCLUDEPATH += $$PWD/include
# Specifies a list of directories for qmake to scan, to resolve dependencies.
DEPENDPATH += $$PWD/include

# qmake adds the values of this variable as compiler C preprocessor macros (-D option).
DEFINES += QT_DEPRECATED_WARNINGS

# Specifies the name of the resource collection files (qrc) for the target.
RESOURCES += \
    resources/resources.qrc

# Specifies the UI files (see Qt Designer Manual) to be processed by uic before compiling.
FORMS += \
    src/gui/windows/dialogs/accountmanager/accountmanagerdialog.ui \
    src/gui/windows/dialogs/accountmanager/forms/addaccountform.ui \
    src/gui/windows/dialogs/accountmanager/forms/charactercreatorform.ui \
    src/gui/windows/dialogs/accountmanager/forms/configurationform.ui \
    src/gui/windows/dialogs/accountmanager/forms/loaderaccountform.ui \
    src/gui/windows/dialogs/accountmanager/forms/subscriptionform.ui \
    src/gui/windows/dialogs/connectiondialog.ui \
    src/gui/windows/forms/accountform.ui \
    src/gui/windows/forms/widgets/characterform.ui \
    src/gui/windows/forms/widgets/consoleform.ui \
    src/gui/utils/boxes/addfloodmessagedialog.ui \
    src/gui/utils/boxes/addspelldialog.ui \
    src/gui/utils/boxes/smileysdialog.ui \
    src/gui/utils/boxes/treewidgetdialog.ui \
    src/gui/windows/forms/widgets/fightform.ui \
    src/gui/windows/forms/widgets/floodform.ui \
    src/gui/windows/forms/widgets/inventoryform.ui \
    src/gui/windows/forms/widgets/mapform.ui \
    src/gui/windows/forms/widgets/settingsform.ui \
    src/gui/windows/forms/widgets/statisticsform.ui \
    src/gui/windows/mainwindow.ui

# Defines the header files for the project.
HEADERS += \
    src/core/CoreEngine.h \
    src/core/DataHandler.h \
    src/core/process/ProcessEngine.h \
    src/core/process/frames/AbstractFrame.h \
    src/core/process/frames/common/basic/CommonBasicFrame.h \
    src/core/process/frames/connection/ConnectionFrame.h \
    src/core/process/frames/connection/register/ConnectionRegisterFrame.h \
    src/core/process/frames/connection/search/ConnectionSearchFrame.h \
    src/core/process/frames/game/achievement/AchievementFrame.h \
    src/core/process/frames/game/actions/GameActionsFrame.h \
    src/core/process/frames/game/actions/fight/GameActionsFightFrame.h \
    src/core/process/frames/game/actions/sequence/GameActionsSequenceFrame.h \
    src/core/process/frames/game/alliance/GameAllianceFrame.h \
    src/core/process/frames/game/almanach/GameAlmanachFrame.h \
    src/core/process/frames/game/approach/GameApproachFrame.h \
    src/core/process/frames/game/atlas/compass/GameAtlasCompassFrame.h \
    src/core/process/frames/game/basic/GameBasicFrame.h \
    src/core/process/frames/game/character/choice/GameCharacterChoiceFrame.h \
    src/core/process/frames/game/character/creation/GameCharacterCreationFrame.h \
    src/core/process/frames/game/character/deletion/GameCharacterDeletionFrame.h \
    src/core/process/frames/game/character/stats/GameCharacterStatsFrame.h \
    src/core/process/frames/game/character/status/GameCharacterStatusFrame.h \
    src/core/process/frames/game/chat/GameChatFrame.h \
    src/core/process/frames/game/chat/channel/GameChatChannelFrame.h \
    src/core/process/frames/game/context/GameContextFrame.h \
    src/core/process/frames/game/context/fight/GameContextFightFrame.h \
    src/core/process/frames/game/context/fight/character/GameContextFightCharacterFrame.h \
    src/core/process/frames/game/context/mount/GameContextMountFrame.h \
    src/core/process/frames/game/context/notification/GameContextNotificationFrame.h \
    src/core/process/frames/game/context/roleplay/GameContextRoleplayFrame.h \
    src/core/process/frames/game/context/roleplay/death/GameContextRoleplayDeathFrame.h \
    src/core/process/frames/game/context/roleplay/emote/GameContextRoleplayEmoteFrame.h \
    src/core/process/frames/game/context/roleplay/fight/GameContextRoleplayFightFrame.h \
    src/core/process/frames/game/context/roleplay/house/GameContextRoplayHouseFrame.h \
    src/core/process/frames/game/context/roleplay/job/GameContextRoleplayJobFrame.h \
    src/core/process/frames/game/context/roleplay/npc/GameContextRoleplayNpcFrame.h \
    src/core/process/frames/game/context/roleplay/objects/GameContextRoleplayObjectsFrame.h \
    src/core/process/frames/game/context/roleplay/party/GameContextRoleplayPartyFrame.h \
    src/core/process/frames/game/context/roleplay/quest/GameContextRoleplayQuestFrame.h \
    src/core/process/frames/game/context/roleplay/stats/GameContextRoleplayStatsFrame.h \
    src/core/process/frames/game/context/roleplay/treasureHunt/GameContextRoleplayTreasureHuntFrame.h \
    src/core/process/frames/game/dialog/GameDialogFrame.h \
    src/core/process/frames/game/friend/GameFriendFrame.h \
    src/core/process/frames/game/guild/GameGuildFrame.h \
    src/core/process/frames/game/initialization/GameInitializationFrame.h \
    src/core/process/frames/game/interactive/GameInteractiveFrame.h \
    src/core/process/frames/game/interactive/zaap/GameInteractiveZaapFrame.h \
    src/core/process/frames/game/inventory/GameInventoryFrame.h \
    src/core/process/frames/game/inventory/exchanges/GameInventoryExchangesFrame.h \
    src/core/process/frames/game/inventory/items/GameInventoryItemsFrame.h \
    src/core/process/frames/game/inventory/spells/GameInventorySpellsFrame.h \
    src/core/process/frames/game/inventory/storage/GameInventoryStorageFrame.h \
    src/core/process/frames/game/look/GameLookFrame.h \
    src/core/process/frames/game/moderation/GameModerationFrame.h \
    src/core/process/frames/game/preset/GamePresetFrame.h \
    src/core/process/frames/game/prism/GamePrismFrame.h \
    src/core/process/frames/game/subscriber/GameSubscriberFrame.h \
    src/core/process/frames/game/tinsel/GameTinselFrame.h \
    src/core/process/frames/handshake/HandshakeFrame.h \
    src/core/process/frames/queues/QueueFrame.h \
    src/core/process/frames/secure/SecureFrame.h \
    src/core/process/frames/security/SecurityFrame.h \
    src/core/process/frames/server/basic/ServerBasicFrame.h \
    src/core/process/frames/shop/ShopModule.h \
    src/core/process/frames/subscription/SubscriptionFrame.h \
    src/core/process/frames/web/WebHaapiFrame.h \
    src/core/process/managers/AbstractManager.h \
    src/core/process/managers/connection/ConnectionManager.h \
    src/core/process/managers/craft/CraftManager.h \
    src/core/process/managers/exchange/ExchangeManager.h \
    src/core/process/managers/farm/FarmManager.h \
    src/core/process/managers/fight/FightManager.h \
    src/core/process/managers/flood/FloodManager.h \
    src/core/process/managers/group/GroupManager.h \
    src/core/process/managers/interaction/InteractionManager.h \
    src/core/process/managers/map/MapManager.h \
    src/core/process/managers/security/SecurityManager.h \
    src/core/process/managers/stats/StatsManager.h \
    src/gamedata/bin/BINFile.h \
    src/gamedata/bin/BINFolder.h \
    src/gamedata/bin/BINManager.h \
    src/gamedata/bin/world/Edge.h \
    src/gamedata/bin/world/Transition.h \
    src/gamedata/bin/world/Vertex.h \
    src/gamedata/bin/world/WorldGraph.h \
    src/gamedata/d2o/D2OClassDefinition.h \
    src/gamedata/d2o/D2OField.h \
    src/gamedata/d2o/D2OFile.h \
    src/gamedata/d2o/D2OFileAccessor.h \
    src/gamedata/d2o/D2OManager.h \
    src/gamedata/d2p/CompressedMap.h \
    src/gamedata/d2p/D2PManager.h \
    src/gamedata/d2p/D2pFile.h \
    src/gamedata/d2p/D2pFolder.h \
    src/gamedata/d2p/map/CellData.h \
    src/gamedata/d2p/map/Fixture.h \
    src/gamedata/d2p/map/Layer.h \
    src/gamedata/d2p/map/Map.h \
    src/gamedata/d2p/map/MapCell.h \
    src/gamedata/d2p/map/WorldPoint.h \
    src/gamedata/d2p/map/elements/BasicElement.h \
    src/gamedata/d2p/map/elements/GraphicalElement.h \
    src/gamedata/d2p/map/elements/SoundElement.h \
    src/gamedata/d2p/map/elements/enums/ElementTypesEnum.h \
    src/gamedata/i18n/I18nFile.h \
    src/gamedata/i18n/I18nFileAccessor.h \
    src/gui/utils/boxes/addfloodmessagedialog.h \
    src/gui/utils/boxes/addspelldialog.h \
    src/gui/utils/boxes/smileysdialog.h \
    src/gui/utils/boxes/treewidgetdialog.h \
    src/gui/utils/delegate/qtreewidgetitemdelegate.h \
    src/gui/utils/theme.h \
    src/gui/utils/threads/ThreadInitGameData.h \
    src/gui/windows/dialogs/accountmanager/accountmanagerdialog.h \
    src/gui/windows/dialogs/accountmanager/widgets/addaccountform.h \
    src/gui/windows/dialogs/accountmanager/widgets/charactercreatorform.h \
    src/gui/windows/dialogs/accountmanager/widgets/configurationform.h \
    src/gui/windows/dialogs/accountmanager/widgets/loaderaccountform.h \
    src/gui/windows/dialogs/accountmanager/widgets/subscriptionform.h \
    src/gui/windows/dialogs/connectiondialog.h \
    src/gui/windows/forms/accountform.h \
    src/gui/windows/forms/widgets/characterform.h \
    src/gui/windows/forms/widgets/consoleform.h \
    src/gui/windows/forms/widgets/fightform.h \
    src/gui/windows/forms/widgets/floodform.h \
    src/gui/windows/forms/widgets/inventoryform.h \
    src/gui/windows/forms/widgets/mapform.h \
    src/gui/windows/forms/widgets/settingsform.h \
    src/gui/windows/forms/widgets/statisticsform.h \
    src/gui/windows/mainwindow.h \
    src/network/Buffer.h \
    src/network/Sniffer.h \
    src/network/SocketIO.h \
    src/protocol/datacenter/AbstractGameData.h \
    src/protocol/network/messages/AbstractMessage.h \
    src/protocol/network/types/AbstractClass.h \
    src/utils/ParamsDecoder.h \
    src/utils/PropertyHelper.h \
    src/utils/Public.h \
    src/utils/Singleton.h \
    src/utils/entitylook/DefaultableColor.h \
    src/utils/entitylook/EntityLookAdapter.h \
    src/utils/entitylook/EntityLookParser.h \
    src/utils/entitylook/TiphonEntityLook.h \
    src/utils/io/Reader.h \
    src/utils/io/Writer.h \
    src/utils/io/type/BooleanByteWrapper.h \
    src/utils/io/type/FuncTree.h \
    src/utils/logger/LogOutput.h \
    src/utils/pathfinding/map/Node.h \
    src/utils/pathfinding/map/Pathfinding.h \
    src/utils/pathfinding/world/MapNode.h \
    src/utils/pathfinding/world/PathfindingMap.h \
    src/utils/security/AesManager.h \
    src/utils/security/RsaManager.h


# Specifies the names of all source files in the project.
SOURCES += \
    src/core/CoreEngine.cpp \
    src/core/DataHandler.cpp \
    src/core/process/ProcessEngine.cpp \
    src/core/process/frames/AbstractFrame.cpp \
    src/core/process/frames/common/basic/CommonBasicFrame.cpp \
    src/core/process/frames/connection/ConnectionFrame.cpp \
    src/core/process/frames/connection/register/ConnectionRegisterFrame.cpp \
    src/core/process/frames/connection/search/ConnectionSearchFrame.cpp \
    src/core/process/frames/game/achievement/AchievementFrame.cpp \
    src/core/process/frames/game/actions/GameActionsFrame.cpp \
    src/core/process/frames/game/actions/fight/GameActionsFightFrame.cpp \
    src/core/process/frames/game/actions/sequence/GameActionsSequenceFrame.cpp \
    src/core/process/frames/game/alliance/GameAllianceFrame.cpp \
    src/core/process/frames/game/almanach/GameAlmanachFrame.cpp \
    src/core/process/frames/game/approach/GameApproachFrame.cpp \
    src/core/process/frames/game/atlas/compass/GameAtlasCompassFrame.cpp \
    src/core/process/frames/game/basic/GameBasicFrame.cpp \
    src/core/process/frames/game/character/choice/GameCharacterChoiceFrame.cpp \
    src/core/process/frames/game/character/creation/GameCharacterCreationFrame.cpp \
    src/core/process/frames/game/character/deletion/GameCharacterDeletionFrame.cpp \
    src/core/process/frames/game/character/stats/GameCharacterStatsFrame.cpp \
    src/core/process/frames/game/character/status/GameCharacterStatusFrame.cpp \
    src/core/process/frames/game/chat/GameChatFrame.cpp \
    src/core/process/frames/game/chat/channel/GameChatChannelFrame.cpp \
    src/core/process/frames/game/context/GameContextFrame.cpp \
    src/core/process/frames/game/context/fight/GameContextFightFrame.cpp \
    src/core/process/frames/game/context/fight/character/GameContextFightCharacterFrame.cpp \
    src/core/process/frames/game/context/mount/GameContextMountFrame.cpp \
    src/core/process/frames/game/context/notification/GameContextNotificationFrame.cpp \
    src/core/process/frames/game/context/roleplay/GameContextRoleplayFrame.cpp \
    src/core/process/frames/game/context/roleplay/death/GameContextRoleplayDeathFrame.cpp \
    src/core/process/frames/game/context/roleplay/emote/GameContextRoleplayEmoteFrame.cpp \
    src/core/process/frames/game/context/roleplay/fight/GameContextRoleplayFightFrame.cpp \
    src/core/process/frames/game/context/roleplay/house/GameContextRoplayHouseFrame.cpp \
    src/core/process/frames/game/context/roleplay/job/GameContextRoleplayJobFrame.cpp \
    src/core/process/frames/game/context/roleplay/npc/GameContextRoleplayNpcFrame.cpp \
    src/core/process/frames/game/context/roleplay/objects/GameContextRoleplayObjectsFrame.cpp \
    src/core/process/frames/game/context/roleplay/party/GameContextRoleplayPartyFrame.cpp \
    src/core/process/frames/game/context/roleplay/quest/GameContextRoleplayQuestFrame.cpp \
    src/core/process/frames/game/context/roleplay/stats/GameContextRoleplayStatsFrame.cpp \
    src/core/process/frames/game/context/roleplay/treasureHunt/GameContextRoleplayTreasureHuntFrame.cpp \
    src/core/process/frames/game/dialog/GameDialogFrame.cpp \
    src/core/process/frames/game/friend/GameFriendFrame.cpp \
    src/core/process/frames/game/guild/GameGuildFrame.cpp \
    src/core/process/frames/game/initialization/GameInitializationFrame.cpp \
    src/core/process/frames/game/interactive/GameInteractiveFrame.cpp \
    src/core/process/frames/game/interactive/zaap/GameInteractiveZaapFrame.cpp \
    src/core/process/frames/game/inventory/GameInventoryFrame.cpp \
    src/core/process/frames/game/inventory/exchanges/GameInventoryExchangesFrame.cpp \
    src/core/process/frames/game/inventory/items/GameInventoryItemsFrame.cpp \
    src/core/process/frames/game/inventory/spells/GameInventorySpellsFrame.cpp \
    src/core/process/frames/game/inventory/storage/GameInventoryStorageFrame.cpp \
    src/core/process/frames/game/look/GameLookFrame.cpp \
    src/core/process/frames/game/moderation/GameModerationFrame.cpp \
    src/core/process/frames/game/preset/GamePresetFrame.cpp \
    src/core/process/frames/game/prism/GamePrismFrame.cpp \
    src/core/process/frames/game/subscriber/GameSubscriberFrame.cpp \
    src/core/process/frames/game/tinsel/GameTinselFrame.cpp \
    src/core/process/frames/handshake/HandshakeFrame.cpp \
    src/core/process/frames/queues/QueueFrame.cpp \
    src/core/process/frames/secure/SecureFrame.cpp \
    src/core/process/frames/security/SecurityFrame.cpp \
    src/core/process/frames/server/basic/ServerBasicFrame.cpp \
    src/core/process/frames/shop/ShopModule.cpp \
    src/core/process/frames/subscription/SubscriptionFrame.cpp \
    src/core/process/frames/web/WebHaapiFrame.cpp \
    src/core/process/managers/AbstractManager.cpp \
    src/core/process/managers/connection/ConnectionManager.cpp \
    src/core/process/managers/craft/CraftManager.cpp \
    src/core/process/managers/exchange/ExchangeManager.cpp \
    src/core/process/managers/farm/FarmManager.cpp \
    src/core/process/managers/fight/FightManager.cpp \
    src/core/process/managers/flood/FloodManager.cpp \
    src/core/process/managers/group/GroupManager.cpp \
    src/core/process/managers/interaction/InteractionManager.cpp \
    src/core/process/managers/map/MapManager.cpp \
    src/core/process/managers/security/SecurityManager.cpp \
    src/core/process/managers/stats/StatsManager.cpp \
    src/gamedata/bin/BINFile.cpp \
    src/gamedata/bin/BINFolder.cpp \
    src/gamedata/bin/BINManager.cpp \
    src/gamedata/bin/world/Edge.cpp \
    src/gamedata/bin/world/Transition.cpp \
    src/gamedata/bin/world/Vertex.cpp \
    src/gamedata/bin/world/WorldGraph.cpp \
    src/gamedata/d2o/D2OClassDefinition.cpp \
    src/gamedata/d2o/D2OField.cpp \
    src/gamedata/d2o/D2OFile.cpp \
    src/gamedata/d2o/D2OFileAccessor.cpp \
    src/gamedata/d2o/D2OManager.cpp \
    src/gamedata/d2p/CompressedMap.cpp \
    src/gamedata/d2p/D2PFile.cpp \
    src/gamedata/d2p/D2PFolder.cpp \
    src/gamedata/d2p/D2PManager.cpp \
    src/gamedata/d2p/map/CellData.cpp \
    src/gamedata/d2p/map/Fixture.cpp \
    src/gamedata/d2p/map/Layer.cpp \
    src/gamedata/d2p/map/Map.cpp \
    src/gamedata/d2p/map/MapCell.cpp \
    src/gamedata/d2p/map/WorldPoint.cpp \
    src/gamedata/d2p/map/elements/BasicElement.cpp \
    src/gamedata/d2p/map/elements/GraphicalElement.cpp \
    src/gamedata/d2p/map/elements/SoundElement.cpp \
    src/gamedata/i18n/I18nFile.cpp \
    src/gamedata/i18n/I18nFileAccessor.cpp \
    src/gui/utils/boxes/addfloodmessagedialog.cpp \
    src/gui/utils/boxes/addspelldialog.cpp \
    src/gui/utils/boxes/smileysdialog.cpp \
    src/gui/utils/boxes/treewidgetdialog.cpp \
    src/gui/utils/delegate/qtreewidgetitemdelegate.cpp \
    src/gui/utils/theme.cpp \
    src/gui/windows/dialogs/accountmanager/accountmanagerdialog.cpp \
    src/gui/windows/dialogs/accountmanager/widgets/addaccountform.cpp \
    src/gui/windows/dialogs/accountmanager/widgets/charactercreatorform.cpp \
    src/gui/windows/dialogs/accountmanager/widgets/configurationform.cpp \
    src/gui/windows/dialogs/accountmanager/widgets/loaderaccountform.cpp \
    src/gui/windows/dialogs/accountmanager/widgets/subscriptionform.cpp \
    src/gui/windows/dialogs/connectiondialog.cpp \
    src/gui/windows/forms/accountform.cpp \
    src/gui/windows/forms/widgets/characterform.cpp \
    src/gui/windows/forms/widgets/consoleform.cpp \
    src/gui/windows/forms/widgets/fightform.cpp \
    src/gui/windows/forms/widgets/floodform.cpp \
    src/gui/windows/forms/widgets/inventoryform.cpp \
    src/gui/windows/forms/widgets/mapform.cpp \
    src/gui/windows/forms/widgets/settingsform.cpp \
    src/gui/windows/forms/widgets/statisticsform.cpp \
    src/gui/windows/mainwindow.cpp \
    src/main.cpp \
    src/network/Buffer.cpp \
    src/network/Sniffer.cpp \
    src/network/SocketIO.cpp \
    src/protocol/datacenter/AbstractGameData.cpp \
    src/utils/ParamsDecoder.cpp \
    src/utils/Public.cpp \
    src/utils/entitylook/DefaultableColor.cpp \
    src/utils/entitylook/EntityLookAdapter.cpp \
    src/utils/entitylook/EntityLookParser.cpp \
    src/utils/entitylook/TiphonEntityLook.cpp \
    src/utils/io/Reader.cpp \
    src/utils/io/Writer.cpp \
    src/utils/io/type/BooleanByteWrapper.cpp \
    src/utils/io/type/FuncTree.cpp \
    src/utils/logger/LogOutput.cpp \
    src/utils/pathfinding/map/Node.cpp \
    src/utils/pathfinding/map/Pathfinding.cpp \
    src/utils/pathfinding/world/MapNode.cpp \
    src/utils/pathfinding/world/PathfindingMap.cpp \
    src/utils/security/AesManager.cpp \
    src/utils/security/RsaManager.cpp


# Specifies a list of files to be included in the dist target.
DISTFILES += \
    resources/qml/Map.qml
