#ifndef TELEPORTTOBUDDYCLOSEMESSAGE_H
#define TELEPORTTOBUDDYCLOSEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class TeleportToBuddyCloseMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TeleportToBuddyCloseMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TeleportToBuddyCloseMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TeleportToBuddyCloseMessage(FuncTree tree);
  TeleportToBuddyCloseMessage();

  uint dungeonId;
  double buddyId;

private:
  void _dungeonIdFunc(Reader *input);
  void _buddyIdFunc(Reader *input);
};

#endif // TELEPORTTOBUDDYCLOSEMESSAGE_H