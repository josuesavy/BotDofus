#ifndef OBJECTITEMTOSELLINBID_H
#define OBJECTITEMTOSELLINBID_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/data/items/ObjectItemToSell.h"
#include "src/protocol/network/types/data/game/data/items/effects/ObjectEffect.h"
#include "src/utils/io/type/FuncTree.h"

class ObjectItemToSellInBid : public ObjectItemToSell
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectItemToSellInBid(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectItemToSellInBid(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectItemToSellInBid(FuncTree tree);
  ObjectItemToSellInBid();
  bool operator==(const ObjectItemToSellInBid &compared);

  uint unsoldDelay;

private:
  void _unsoldDelayFunc(Reader *input);
};

#endif // OBJECTITEMTOSELLINBID_H