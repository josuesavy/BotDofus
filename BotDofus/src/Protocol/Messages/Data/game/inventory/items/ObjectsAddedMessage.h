#ifndef OBJECTSADDEDMESSAGE_H
#define OBJECTSADDEDMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/ObjectItem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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