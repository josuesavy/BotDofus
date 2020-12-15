#ifndef DUNGEONPARTYFINDERREGISTERREQUESTMESSAGE_H
#define DUNGEONPARTYFINDERREGISTERREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class DungeonPartyFinderRegisterRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_DungeonPartyFinderRegisterRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_DungeonPartyFinderRegisterRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_DungeonPartyFinderRegisterRequestMessage(FuncTree tree);
  DungeonPartyFinderRegisterRequestMessage();

  QList<uint> dungeonIds;

private:
  void _dungeonIdstreeFunc(Reader *input);
  void _dungeonIdsFunc(Reader *input);

  FuncTree _dungeonIdstree;
};

#endif // DUNGEONPARTYFINDERREGISTERREQUESTMESSAGE_H