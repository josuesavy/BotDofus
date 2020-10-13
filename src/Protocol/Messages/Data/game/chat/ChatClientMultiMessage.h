#ifndef CHATCLIENTMULTIMESSAGE_H
#define CHATCLIENTMULTIMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/chat/ChatAbstractClientMessage.h"

class ChatClientMultiMessage : public ChatAbstractClientMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChatClientMultiMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChatClientMultiMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChatClientMultiMessage(FuncTree tree);
  ChatClientMultiMessage();

  uint channel;

private:
  void _channelFunc(Reader *input);
};

#endif // CHATCLIENTMULTIMESSAGE_H