#ifndef OBJECTEFFECTMINMAX_H
#define OBJECTEFFECTMINMAX_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/data/items/effects/ObjectEffect.h"
#include "src/utils/io/type/FuncTree.h"

class ObjectEffectMinMax : public ObjectEffect
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectEffectMinMax(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectEffectMinMax(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectEffectMinMax(FuncTree tree);
  ObjectEffectMinMax();
  bool operator==(const ObjectEffectMinMax &compared);

  uint min;
  uint max;

private:
  void _minFunc(Reader *input);
  void _maxFunc(Reader *input);
};

#endif // OBJECTEFFECTMINMAX_H