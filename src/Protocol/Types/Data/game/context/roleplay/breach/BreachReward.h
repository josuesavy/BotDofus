#ifndef BREACHREWARD_H
#define BREACHREWARD_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class BreachReward : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachReward(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachReward(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachReward(FuncTree tree);
  BreachReward();
  bool operator==(const BreachReward &compared);

  uint id;
  QList<uint> buyLocks;
  QString buyCriterion;
  int remainingQty;
  uint price;

private:
  void _idFunc(Reader *input);
  void _buyLockstreeFunc(Reader *input);
  void _buyLocksFunc(Reader *input);
  void _buyCriterionFunc(Reader *input);
  void _remainingQtyFunc(Reader *input);
  void _priceFunc(Reader *input);

  FuncTree _buyLockstree;
};

#endif // BREACHREWARD_H