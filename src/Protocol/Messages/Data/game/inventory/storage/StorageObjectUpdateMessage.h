#ifndef STORAGEOBJECTUPDATEMESSAGE_H
#define STORAGEOBJECTUPDATEMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/ObjectItem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class StorageObjectUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StorageObjectUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StorageObjectUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StorageObjectUpdateMessage(FuncTree tree);
  StorageObjectUpdateMessage();

  QSharedPointer<ObjectItem> object;

private:
  void _objecttreeFunc(Reader *input);

  FuncTree _objecttree;
};

#endif // STORAGEOBJECTUPDATEMESSAGE_H