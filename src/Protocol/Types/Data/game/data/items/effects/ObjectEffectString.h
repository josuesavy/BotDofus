#ifndef OBJECTEFFECTSTRING_H
#define OBJECTEFFECTSTRING_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffect.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class ObjectEffectString : public ObjectEffect
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectEffectString(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectEffectString(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectEffectString(FuncTree tree);
  ObjectEffectString();
  bool operator==(const ObjectEffectString &compared);

  QString value;

private:
  void _valueFunc(Reader *input);
};

#endif // OBJECTEFFECTSTRING_H