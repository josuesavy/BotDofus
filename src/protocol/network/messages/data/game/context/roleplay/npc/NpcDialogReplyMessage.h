#ifndef NPCDIALOGREPLYMESSAGE_H
#define NPCDIALOGREPLYMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class NpcDialogReplyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_NpcDialogReplyMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_NpcDialogReplyMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_NpcDialogReplyMessage(FuncTree tree);
  NpcDialogReplyMessage();

  uint replyId;

private:
  void _replyIdFunc(Reader *input);
};

#endif // NPCDIALOGREPLYMESSAGE_H