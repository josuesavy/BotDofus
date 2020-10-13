#ifndef OBTAINEDITEMWITHBONUSMESSAGE_H
#define OBTAINEDITEMWITHBONUSMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/items/ObtainedItemMessage.h"

class ObtainedItemWithBonusMessage : public ObtainedItemMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObtainedItemWithBonusMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObtainedItemWithBonusMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObtainedItemWithBonusMessage(FuncTree tree);
  ObtainedItemWithBonusMessage();

  uint bonusQuantity;

private:
  void _bonusQuantityFunc(Reader *input);
};

#endif // OBTAINEDITEMWITHBONUSMESSAGE_H