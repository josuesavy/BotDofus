#ifndef CHATSERVERCOPYWITHOBJECTMESSAGE_H
#define CHATSERVERCOPYWITHOBJECTMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/ObjectItem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/chat/ChatServerCopyMessage.h"

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