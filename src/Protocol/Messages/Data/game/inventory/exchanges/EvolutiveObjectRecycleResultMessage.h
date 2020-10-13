#ifndef EVOLUTIVEOBJECTRECYCLERESULTMESSAGE_H
#define EVOLUTIVEOBJECTRECYCLERESULTMESSAGE_H

#include "src/Protocol/Types/Data/game/inventory/exchanges/RecycledItem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class EvolutiveObjectRecycleResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_EvolutiveObjectRecycleResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_EvolutiveObjectRecycleResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_EvolutiveObjectRecycleResultMessage(FuncTree tree);
  EvolutiveObjectRecycleResultMessage();

  QList<RecycledItem> recycledItems;

private:
  void _recycledItemstreeFunc(Reader *input);
  void _recycledItemsFunc(Reader *input);

  FuncTree _recycledItemstree;
};

#endif // EVOLUTIVEOBJECTRECYCLERESULTMESSAGE_H