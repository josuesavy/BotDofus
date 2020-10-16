#ifndef DUNGEONPARTYFINDERAVAILABLEDUNGEONSREQUESTMESSAGE_H
#define DUNGEONPARTYFINDERAVAILABLEDUNGEONSREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class DungeonPartyFinderAvailableDungeonsRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_DungeonPartyFinderAvailableDungeonsRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_DungeonPartyFinderAvailableDungeonsRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_DungeonPartyFinderAvailableDungeonsRequestMessage(FuncTree tree);
  DungeonPartyFinderAvailableDungeonsRequestMessage();
};

#endif // DUNGEONPARTYFINDERAVAILABLEDUNGEONSREQUESTMESSAGE_H