#ifndef OBJECTSDELETEDMESSAGE_H
#define OBJECTSDELETEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ObjectsDeletedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectsDeletedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectsDeletedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectsDeletedMessage(FuncTree tree);
  ObjectsDeletedMessage();

  QList<uint> objectUID;

private:
  void _objectUIDtreeFunc(Reader *input);
  void _objectUIDFunc(Reader *input);

  FuncTree _objectUIDtree;
};

#endif // OBJECTSDELETEDMESSAGE_H