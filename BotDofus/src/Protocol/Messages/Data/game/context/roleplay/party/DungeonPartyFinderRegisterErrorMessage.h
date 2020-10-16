#ifndef DUNGEONPARTYFINDERREGISTERERRORMESSAGE_H
#define DUNGEONPARTYFINDERREGISTERERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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