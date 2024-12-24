#ifndef DUNGEONPARTYFINDERAVAILABLEDUNGEONSMESSAGE_H
#define DUNGEONPARTYFINDERAVAILABLEDUNGEONSMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class DungeonPartyFinderAvailableDungeonsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_DungeonPartyFinderAvailableDungeonsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_DungeonPartyFinderAvailableDungeonsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_DungeonPartyFinderAvailableDungeonsMessage(FuncTree tree);
  DungeonPartyFinderAvailableDungeonsMessage();

  QList<uint> dungeonIds;

private:
  void _dungeonIdstreeFunc(Reader *input);
  void _dungeonIdsFunc(Reader *input);

  FuncTree _dungeonIdstree;
};

#endif // DUNGEONPARTYFINDERAVAILABLEDUNGEONSMESSAGE_H