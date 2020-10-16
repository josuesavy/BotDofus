#ifndef STORAGEOBJECTREMOVEMESSAGE_H
#define STORAGEOBJECTREMOVEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class StorageObjectRemoveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StorageObjectRemoveMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StorageObjectRemoveMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StorageObjectRemoveMessage(FuncTree tree);
  StorageObjectRemoveMessage();

  uint objectUID;

private:
  void _objectUIDFunc(Reader *input);
};

#endif // STORAGEOBJECTREMOVEMESSAGE_H