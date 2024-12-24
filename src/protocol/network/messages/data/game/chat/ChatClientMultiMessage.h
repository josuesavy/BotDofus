#ifndef CHATCLIENTMULTIMESSAGE_H
#define CHATCLIENTMULTIMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/chat/ChatAbstractClientMessage.h"

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