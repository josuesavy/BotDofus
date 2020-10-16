#ifndef OBJECTQUANTITYMESSAGE_H
#define OBJECTQUANTITYMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ObjectQuantityMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectQuantityMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectQuantityMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectQuantityMessage(FuncTree tree);
  ObjectQuantityMessage();

  uint objectUID;
  uint quantity;
  uint origin;

private:
  void _objectUIDFunc(Reader *input);
  void _quantityFunc(Reader *input);
  void _originFunc(Reader *input);
};

#endif // OBJECTQUANTITYMESSAGE_H