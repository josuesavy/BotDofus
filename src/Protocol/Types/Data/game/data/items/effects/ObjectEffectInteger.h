#ifndef OBJECTEFFECTINTEGER_H
#define OBJECTEFFECTINTEGER_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffect.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class ObjectEffectInteger : public ObjectEffect
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectEffectInteger(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectEffectInteger(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectEffectInteger(FuncTree tree);
  ObjectEffectInteger();
  bool operator==(const ObjectEffectInteger &compared);

  uint value;

private:
  void _valueFunc(Reader *input);
};

#endif // OBJECTEFFECTINTEGER_H