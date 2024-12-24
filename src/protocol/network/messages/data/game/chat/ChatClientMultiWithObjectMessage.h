#ifndef CHATCLIENTMULTIWITHOBJECTMESSAGE_H
#define CHATCLIENTMULTIWITHOBJECTMESSAGE_H

#include "src/protocol/network/types/data/game/data/items/ObjectItem.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/chat/ChatClientMultiMessage.h"

class ChatClientMultiWithObjectMessage : public ChatClientMultiMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChatClientMultiWithObjectMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChatClientMultiWithObjectMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChatClientMultiWithObjectMessage(FuncTree tree);
  ChatClientMultiWithObjectMessage();

  QList<QSharedPointer<ObjectItem>> objects;

private:
  void _objectstreeFunc(Reader *input);
  void _objectsFunc(Reader *input);

  FuncTree _objectstree;
};

#endif // CHATCLIENTMULTIWITHOBJECTMESSAGE_H