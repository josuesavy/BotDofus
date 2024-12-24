#ifndef DUNGEONPARTYFINDERAVAILABLEDUNGEONSREQUESTMESSAGE_H
#define DUNGEONPARTYFINDERAVAILABLEDUNGEONSREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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