#ifndef OBJECTEFFECTINTEGER_H
#define OBJECTEFFECTINTEGER_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/data/items/effects/ObjectEffect.h"
#include "src/utils/io/type/FuncTree.h"

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