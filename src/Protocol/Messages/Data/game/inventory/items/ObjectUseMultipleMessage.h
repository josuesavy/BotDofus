#ifndef OBJECTUSEMULTIPLEMESSAGE_H
#define OBJECTUSEMULTIPLEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/items/ObjectUseMessage.h"

class ObjectUseMultipleMessage : public ObjectUseMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectUseMultipleMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectUseMultipleMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectUseMultipleMessage(FuncTree tree);
  ObjectUseMultipleMessage();

  uint quantity;

private:
  void _quantityFunc(Reader *input);
};

#endif // OBJECTUSEMULTIPLEMESSAGE_H