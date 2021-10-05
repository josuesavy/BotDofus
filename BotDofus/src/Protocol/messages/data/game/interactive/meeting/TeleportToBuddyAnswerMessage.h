#ifndef TELEPORTTOBUDDYANSWERMESSAGE_H
#define TELEPORTTOBUDDYANSWERMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class TeleportToBuddyAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TeleportToBuddyAnswerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TeleportToBuddyAnswerMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TeleportToBuddyAnswerMessage(FuncTree tree);
  TeleportToBuddyAnswerMessage();

  uint dungeonId;
  double buddyId;
  bool accept;

private:
  void _dungeonIdFunc(Reader *input);
  void _buddyIdFunc(Reader *input);
  void _acceptFunc(Reader *input);
};

#endif // TELEPORTTOBUDDYANSWERMESSAGE_H