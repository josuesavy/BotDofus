#ifndef DUNGEONPARTYFINDERROOMCONTENTUPDATEMESSAGE_H
#define DUNGEONPARTYFINDERROOMCONTENTUPDATEMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/party/DungeonPartyFinderPlayer.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class DungeonPartyFinderRoomContentUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_DungeonPartyFinderRoomContentUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_DungeonPartyFinderRoomContentUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_DungeonPartyFinderRoomContentUpdateMessage(FuncTree tree);
  DungeonPartyFinderRoomContentUpdateMessage();

  uint dungeonId;
  QList<DungeonPartyFinderPlayer> addedPlayers;
  QList<double> removedPlayersIds;

private:
  void _dungeonIdFunc(Reader *input);
  void _addedPlayerstreeFunc(Reader *input);
  void _addedPlayersFunc(Reader *input);
  void _removedPlayersIdstreeFunc(Reader *input);
  void _removedPlayersIdsFunc(Reader *input);

  FuncTree _addedPlayerstree;
  FuncTree _removedPlayersIdstree;
};

#endif // DUNGEONPARTYFINDERROOMCONTENTUPDATEMESSAGE_H