#ifndef OBJECTEFFECTCREATURE_H
#define OBJECTEFFECTCREATURE_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffect.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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