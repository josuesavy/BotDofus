#ifndef CHATCLIENTPRIVATEWITHOBJECTMESSAGE_H
#define CHATCLIENTPRIVATEWITHOBJECTMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/ObjectItem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/chat/ChatClientPrivateMessage.h"

class ChatClientPrivateWithObjectMessage : public ChatClientPrivateMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChatClientPrivateWithObjectMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChatClientPrivateWithObjectMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChatClientPrivateWithObjectMessage(FuncTree tree);
  ChatClientPrivateWithObjectMessage();

  QList<QSharedPointer<ObjectItem>> objects;

private:
  void _objectstreeFunc(Reader *input);
  void _objectsFunc(Reader *input);

  FuncTree _objectstree;
};

#endif // CHATCLIENTPRIVATEWITHOBJECTMESSAGE_H