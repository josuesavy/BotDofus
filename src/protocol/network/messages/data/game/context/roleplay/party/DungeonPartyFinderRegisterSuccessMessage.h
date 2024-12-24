#ifndef DUNGEONPARTYFINDERREGISTERSUCCESSMESSAGE_H
#define DUNGEONPARTYFINDERREGISTERSUCCESSMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class DungeonPartyFinderRegisterSuccessMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_DungeonPartyFinderRegisterSuccessMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_DungeonPartyFinderRegisterSuccessMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_DungeonPartyFinderRegisterSuccessMessage(FuncTree tree);
  DungeonPartyFinderRegisterSuccessMessage();

  QList<uint> dungeonIds;

private:
  void _dungeonIdstreeFunc(Reader *input);
  void _dungeonIdsFunc(Reader *input);

  FuncTree _dungeonIdstree;
};

#endif // DUNGEONPARTYFINDERREGISTERSUCCESSMESSAGE_H