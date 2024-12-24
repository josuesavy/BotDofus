#ifndef TELEPORTPLAYERCLOSEMESSAGE_H
#define TELEPORTPLAYERCLOSEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class TeleportPlayerCloseMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TeleportPlayerCloseMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TeleportPlayerCloseMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TeleportPlayerCloseMessage(FuncTree tree);
  TeleportPlayerCloseMessage();

  double mapId;
  double requesterId;

private:
  void _mapIdFunc(Reader *input);
  void _requesterIdFunc(Reader *input);
};

#endif // TELEPORTPLAYERCLOSEMESSAGE_H