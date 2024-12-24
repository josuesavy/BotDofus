#ifndef CHATCLIENTPRIVATEMESSAGE_H
#define CHATCLIENTPRIVATEMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/common/AbstractPlayerSearchInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/chat/ChatAbstractClientMessage.h"

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

  QSharedPointer<AbstractPlayerSearchInformation> receiver;

private:
  void _receivertreeFunc(Reader *input);

  FuncTree _receivertree;
};

#endif // CHATCLIENTPRIVATEMESSAGE_H