#ifndef OBJECTEFFECTMOUNT_H
#define OBJECTEFFECTMOUNT_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffectInteger.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffect.h"
#include "src/engines/io/network/utils/BooleanByteWrapper.h"
#include "src/engines/io/network/utils/FuncTree.h"

class ObjectEffectMount : public ObjectEffect
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectEffectMount(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectEffectMount(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectEffectMount(FuncTree tree);
  ObjectEffectMount();
  bool operator==(const ObjectEffectMount &compared);

  double id;
  double expirationDate;
  uint model;
  QString name;
  QString owner;
  uint level;
  bool sex;
  bool isRideable;
  bool isFeconded;
  bool isFecondationReady;
  int reproductionCount;
  uint reproductionCountMax;
  QList<QSharedPointer<ObjectEffectInteger>> effects;
  QList<uint> capacities;

private:
  void deserializeByteBoxes(Reader *input);
  void _idFunc(Reader *input);
  void _expirationDateFunc(Reader *input);
  void _modelFunc(Reader *input);
  void _nameFunc(Reader *input);
  void _ownerFunc(Reader *input);
  void _levelFunc(Reader *input);
  void _reproductionCountFunc(Reader *input);
  void _reproductionCountMaxFunc(Reader *input);
  void _effectstreeFunc(Reader *input);
  void _effectsFunc(Reader *input);
  void _capacitiestreeFunc(Reader *input);
  void _capacitiesFunc(Reader *input);

  FuncTree _effectstree;
  FuncTree _capacitiestree;
};

#endif // OBJECTEFFECTMOUNT_H