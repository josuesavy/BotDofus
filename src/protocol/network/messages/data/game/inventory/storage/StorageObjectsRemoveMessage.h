#ifndef STORAGEOBJECTSREMOVEMESSAGE_H
#define STORAGEOBJECTSREMOVEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class StorageObjectsRemoveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StorageObjectsRemoveMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StorageObjectsRemoveMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StorageObjectsRemoveMessage(FuncTree tree);
  StorageObjectsRemoveMessage();

  QList<uint> objectUIDList;

private:
  void _objectUIDListtreeFunc(Reader *input);
  void _objectUIDListFunc(Reader *input);

  FuncTree _objectUIDListtree;
};

#endif // STORAGEOBJECTSREMOVEMESSAGE_H