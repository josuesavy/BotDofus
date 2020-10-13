#ifndef OBJECTEFFECTS_H
#define OBJECTEFFECTS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffect.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class ObjectEffects : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectEffects(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectEffects(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectEffects(FuncTree tree);
  ObjectEffects();
  bool operator==(const ObjectEffects &compared);

  QList<QSharedPointer<ObjectEffect>> effects;

private:
  void _effectstreeFunc(Reader *input);
  void _effectsFunc(Reader *input);

  FuncTree _effectstree;
};

#endif // OBJECTEFFECTS_H