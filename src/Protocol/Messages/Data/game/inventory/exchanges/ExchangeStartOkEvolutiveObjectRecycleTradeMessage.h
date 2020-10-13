#ifndef EXCHANGESTARTOKEVOLUTIVEOBJECTRECYCLETRADEMESSAGE_H
#define EXCHANGESTARTOKEVOLUTIVEOBJECTRECYCLETRADEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeStartOkEvolutiveObjectRecycleTradeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeStartOkEvolutiveObjectRecycleTradeMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeStartOkEvolutiveObjectRecycleTradeMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeStartOkEvolutiveObjectRecycleTradeMessage(FuncTree tree);
  ExchangeStartOkEvolutiveObjectRecycleTradeMessage();
};

#endif // EXCHANGESTARTOKEVOLUTIVEOBJECTRECYCLETRADEMESSAGE_H