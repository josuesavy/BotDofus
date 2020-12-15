#ifndef OBJECTEFFECTS_H
#define OBJECTEFFECTS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffect.h"
#include "src/protocol/types/ClassManager.h"
#include "src/engines/io/network/utils/FuncTree.h"

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