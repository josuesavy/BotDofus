#ifndef CHATSERVERWITHOBJECTMESSAGE_H
#define CHATSERVERWITHOBJECTMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/ObjectItem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/chat/ChatServerMessage.h"

class ChatServerWithObjectMessage : public ChatServerMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChatServerWithObjectMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChatServerWithObjectMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChatServerWithObjectMessage(FuncTree tree);
  ChatServerWithObjectMessage();

  QList<QSharedPointer<ObjectItem>> objects;

private:
  void _objectstreeFunc(Reader *input);
  void _objectsFunc(Reader *input);

  FuncTree _objectstree;
};

#endif // CHATSERVERWITHOBJECTMESSAGE_H