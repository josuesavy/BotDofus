#ifndef STORAGEOBJECTSREMOVEMESSAGE_H
#define STORAGEOBJECTSREMOVEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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