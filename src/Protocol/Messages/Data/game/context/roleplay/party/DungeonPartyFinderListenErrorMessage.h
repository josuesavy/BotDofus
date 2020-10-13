#ifndef DUNGEONPARTYFINDERLISTENERRORMESSAGE_H
#define DUNGEONPARTYFINDERLISTENERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class DungeonPartyFinderListenErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_DungeonPartyFinderListenErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_DungeonPartyFinderListenErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_DungeonPartyFinderListenErrorMessage(FuncTree tree);
  DungeonPartyFinderListenErrorMessage();

  uint dungeonId;

private:
  void _dungeonIdFunc(Reader *input);
};

#endif // DUNGEONPARTYFINDERLISTENERRORMESSAGE_H