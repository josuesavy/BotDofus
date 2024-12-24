#ifndef CHATSERVERCOPYWITHOBJECTMESSAGE_H
#define CHATSERVERCOPYWITHOBJECTMESSAGE_H

#include "src/protocol/network/types/data/game/data/items/ObjectItem.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/chat/ChatServerCopyMessage.h"

class ChatServerCopyWithObjectMessage : public ChatServerCopyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChatServerCopyWithObjectMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChatServerCopyWithObjectMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChatServerCopyWithObjectMessage(FuncTree tree);
  ChatServerCopyWithObjectMessage();

  QList<QSharedPointer<ObjectItem>> objects;

private:
  void _objectstreeFunc(Reader *input);
  void _objectsFunc(Reader *input);

  FuncTree _objectstree;
};

#endif // CHATSERVERCOPYWITHOBJECTMESSAGE_H