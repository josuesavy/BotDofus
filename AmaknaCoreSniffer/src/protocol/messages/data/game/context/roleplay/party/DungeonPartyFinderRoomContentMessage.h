#ifndef DUNGEONPARTYFINDERROOMCONTENTMESSAGE_H
#define DUNGEONPARTYFINDERROOMCONTENTMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/party/DungeonPartyFinderPlayer.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class DungeonPartyFinderRoomContentMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_DungeonPartyFinderRoomContentMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_DungeonPartyFinderRoomContentMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_DungeonPartyFinderRoomContentMessage(FuncTree tree);
  DungeonPartyFinderRoomContentMessage();

  uint dungeonId;
  QList<DungeonPartyFinderPlayer> players;

private:
  void _dungeonIdFunc(Reader *input);
  void _playerstreeFunc(Reader *input);
  void _playersFunc(Reader *input);

  FuncTree _playerstree;
};

#endif // DUNGEONPARTYFINDERROOMCONTENTMESSAGE_H