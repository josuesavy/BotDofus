#ifndef OBJECTEFFECTCREATURE_H
#define OBJECTEFFECTCREATURE_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/data/items/effects/ObjectEffect.h"
#include "src/utils/io/type/FuncTree.h"

class ObjectEffectCreature : public ObjectEffect
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectEffectCreature(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectEffectCreature(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectEffectCreature(FuncTree tree);
  ObjectEffectCreature();
  bool operator==(const ObjectEffectCreature &compared);

  uint monsterFamilyId;

private:
  void _monsterFamilyIdFunc(Reader *input);
};

#endif // OBJECTEFFECTCREATURE_H