#ifndef OBJECTDELETEDMESSAGE_H
#define OBJECTDELETEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ObjectDeletedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectDeletedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectDeletedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectDeletedMessage(FuncTree tree);
  ObjectDeletedMessage();

  uint objectUID;

private:
  void _objectUIDFunc(Reader *input);
};

#endif // OBJECTDELETEDMESSAGE_H