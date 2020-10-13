#ifndef CHATCLIENTPRIVATEMESSAGE_H
#define CHATCLIENTPRIVATEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/chat/ChatAbstractClientMessage.h"

class ChatClientPrivateMessage : public ChatAbstractClientMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChatClientPrivateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChatClientPrivateMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChatClientPrivateMessage(FuncTree tree);
  ChatClientPrivateMessage();

  QString receiver;

private:
  void _receiverFunc(Reader *input);
};

#endif // CHATCLIENTPRIVATEMESSAGE_H