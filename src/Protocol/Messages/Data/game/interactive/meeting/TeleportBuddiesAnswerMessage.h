#ifndef TELEPORTBUDDIESANSWERMESSAGE_H
#define TELEPORTBUDDIESANSWERMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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