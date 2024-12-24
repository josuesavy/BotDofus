#ifndef TELEPORTBUDDIESANSWERMESSAGE_H
#define TELEPORTBUDDIESANSWERMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class TeleportBuddiesAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TeleportBuddiesAnswerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TeleportBuddiesAnswerMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TeleportBuddiesAnswerMessage(FuncTree tree);
  TeleportBuddiesAnswerMessage();

  bool accept;

private:
  void _acceptFunc(Reader *input);
};

#endif // TELEPORTBUDDIESANSWERMESSAGE_H