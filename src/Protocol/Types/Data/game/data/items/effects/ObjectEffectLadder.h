#ifndef OBJECTEFFECTLADDER_H
#define OBJECTEFFECTLADDER_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffectCreature.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class ObjectEffectLadder : public ObjectEffectCreature
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectEffectLadder(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectEffectLadder(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectEffectLadder(FuncTree tree);
  ObjectEffectLadder();
  bool operator==(const ObjectEffectLadder &compared);

  uint monsterCount;

private:
  void _monsterCountFunc(Reader *input);
};

#endif // OBJECTEFFECTLADDER_H