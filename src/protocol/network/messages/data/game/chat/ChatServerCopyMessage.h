#ifndef CHATSERVERCOPYMESSAGE_H
#define CHATSERVERCOPYMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/chat/ChatAbstractServerMessage.h"

class ChatServerCopyMessage : public ChatAbstractServerMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChatServerCopyMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChatServerCopyMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChatServerCopyMessage(FuncTree tree);
  ChatServerCopyMessage();

  double receiverId;
  QString receiverName;

private:
  void _receiverIdFunc(Reader *input);
  void _receiverNameFunc(Reader *input);
};

#endif // CHATSERVERCOPYMESSAGE_H