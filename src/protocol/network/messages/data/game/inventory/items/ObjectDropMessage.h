#ifndef OBJECTDROPMESSAGE_H
#define OBJECTDROPMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ObjectDropMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectDropMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectDropMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectDropMessage(FuncTree tree);
  ObjectDropMessage();

  uint objectUID;
  uint quantity;

private:
  void _objectUIDFunc(Reader *input);
  void _quantityFunc(Reader *input);
};

#endif // OBJECTDROPMESSAGE_H