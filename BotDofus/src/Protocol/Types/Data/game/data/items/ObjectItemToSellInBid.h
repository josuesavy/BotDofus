#ifndef OBJECTITEMTOSELLINBID_H
#define OBJECTITEMTOSELLINBID_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/data/items/ObjectItemToSell.h"
#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffect.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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