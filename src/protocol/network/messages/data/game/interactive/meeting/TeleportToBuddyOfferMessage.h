#ifndef TELEPORTTOBUDDYOFFERMESSAGE_H
#define TELEPORTTOBUDDYOFFERMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class TeleportToBuddyOfferMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TeleportToBuddyOfferMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TeleportToBuddyOfferMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TeleportToBuddyOfferMessage(FuncTree tree);
  TeleportToBuddyOfferMessage();

  uint dungeonId;
  double buddyId;
  uint timeLeft;

private:
  void _dungeonIdFunc(Reader *input);
  void _buddyIdFunc(Reader *input);
  void _timeLeftFunc(Reader *input);
};

#endif // TELEPORTTOBUDDYOFFERMESSAGE_H