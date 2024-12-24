#ifndef TELEPORTBUDDIESMESSAGE_H
#define TELEPORTBUDDIESMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class TeleportBuddiesMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TeleportBuddiesMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TeleportBuddiesMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TeleportBuddiesMessage(FuncTree tree);
  TeleportBuddiesMessage();

  uint dungeonId;

private:
  void _dungeonIdFunc(Reader *input);
};

#endif // TELEPORTBUDDIESMESSAGE_H