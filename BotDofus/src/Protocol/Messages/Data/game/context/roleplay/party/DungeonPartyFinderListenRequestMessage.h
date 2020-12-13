#ifndef DUNGEONPARTYFINDERLISTENREQUESTMESSAGE_H
#define DUNGEONPARTYFINDERLISTENREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class DungeonPartyFinderListenRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_DungeonPartyFinderListenRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_DungeonPartyFinderListenRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_DungeonPartyFinderListenRequestMessage(FuncTree tree);
  DungeonPartyFinderListenRequestMessage();

  uint dungeonId;

private:
  void _dungeonIdFunc(Reader *input);
};

#endif // DUNGEONPARTYFINDERLISTENREQUESTMESSAGE_H