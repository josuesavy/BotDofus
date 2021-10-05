#ifndef OBJECTDELETEMESSAGE_H
#define OBJECTDELETEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ObjectDeleteMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectDeleteMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectDeleteMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectDeleteMessage(FuncTree tree);
  ObjectDeleteMessage();

  uint objectUID;
  uint quantity;

private:
  void _objectUIDFunc(Reader *input);
  void _quantityFunc(Reader *input);
};

#endif // OBJECTDELETEMESSAGE_H