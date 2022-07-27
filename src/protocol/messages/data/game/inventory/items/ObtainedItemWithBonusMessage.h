#ifndef OBTAINEDITEMWITHBONUSMESSAGE_H
#define OBTAINEDITEMWITHBONUSMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/inventory/items/ObtainedItemMessage.h"

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