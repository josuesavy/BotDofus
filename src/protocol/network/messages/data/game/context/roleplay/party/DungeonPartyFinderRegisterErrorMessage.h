#ifndef DUNGEONPARTYFINDERREGISTERERRORMESSAGE_H
#define DUNGEONPARTYFINDERREGISTERERRORMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class DungeonPartyFinderRegisterErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_DungeonPartyFinderRegisterErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_DungeonPartyFinderRegisterErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_DungeonPartyFinderRegisterErrorMessage(FuncTree tree);
  DungeonPartyFinderRegisterErrorMessage();
};

#endif // DUNGEONPARTYFINDERREGISTERERRORMESSAGE_H