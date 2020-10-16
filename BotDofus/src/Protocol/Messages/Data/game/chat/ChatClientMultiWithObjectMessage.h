#ifndef CHATCLIENTMULTIWITHOBJECTMESSAGE_H
#define CHATCLIENTMULTIWITHOBJECTMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/ObjectItem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/chat/ChatClientMultiMessage.h"

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