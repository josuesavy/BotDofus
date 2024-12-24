#ifndef OBJECTSADDEDMESSAGE_H
#define OBJECTSADDEDMESSAGE_H

#include "src/protocol/network/types/data/game/data/items/ObjectItem.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ObjectsAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectsAddedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectsAddedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectsAddedMessage(FuncTree tree);
  ObjectsAddedMessage();

  QList<QSharedPointer<ObjectItem>> object;

private:
  void _objecttreeFunc(Reader *input);
  void _objectFunc(Reader *input);

  FuncTree _objecttree;
};

#endif // OBJECTSADDEDMESSAGE_H