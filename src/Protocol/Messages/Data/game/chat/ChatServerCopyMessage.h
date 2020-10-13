#ifndef CHATSERVERCOPYMESSAGE_H
#define CHATSERVERCOPYMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/chat/ChatAbstractServerMessage.h"

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