#ifndef STORAGEOBJECTSUPDATEMESSAGE_H
#define STORAGEOBJECTSUPDATEMESSAGE_H

#include "src/protocol/types/data/game/data/items/ObjectItem.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class StorageObjectsUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StorageObjectsUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StorageObjectsUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StorageObjectsUpdateMessage(FuncTree tree);
  StorageObjectsUpdateMessage();

  QList<QSharedPointer<ObjectItem>> objectList;

private:
  void _objectListtreeFunc(Reader *input);
  void _objectListFunc(Reader *input);

  FuncTree _objectListtree;
};

#endif // STORAGEOBJECTSUPDATEMESSAGE_H