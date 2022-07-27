#ifndef TELEPORTPLAYEROFFERMESSAGE_H
#define TELEPORTPLAYEROFFERMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class TeleportPlayerOfferMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TeleportPlayerOfferMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TeleportPlayerOfferMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TeleportPlayerOfferMessage(FuncTree tree);
  TeleportPlayerOfferMessage();

  double mapId;
  QString message;
  uint timeLeft;
  double requesterId;

private:
  void _mapIdFunc(Reader *input);
  void _messageFunc(Reader *input);
  void _timeLeftFunc(Reader *input);
  void _requesterIdFunc(Reader *input);
};

#endif // TELEPORTPLAYEROFFERMESSAGE_H