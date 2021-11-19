#ifndef BREACHBONUSMESSAGE_H
#define BREACHBONUSMESSAGE_H

#include "src/protocol/types/data/game/data/items/effects/ObjectEffectInteger.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class BreachBonusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachBonusMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachBonusMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachBonusMessage(FuncTree tree);
  BreachBonusMessage();

  QSharedPointer<ObjectEffectInteger> bonus;

private:
  void _bonustreeFunc(Reader *input);

  FuncTree _bonustree;
};

#endif // BREACHBONUSMESSAGE_H