#ifndef FIGHTLOOTOBJECT_H
#define FIGHTLOOTOBJECT_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class FightLootObject : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightLootObject(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightLootObject(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightLootObject(FuncTree tree);
  FightLootObject();
  bool operator==(const FightLootObject &compared);

  int objectId;
  int quantity;
  int priorityHint;

private:
  void _objectIdFunc(Reader *input);
  void _quantityFunc(Reader *input);
  void _priorityHintFunc(Reader *input);
};

#endif // FIGHTLOOTOBJECT_H