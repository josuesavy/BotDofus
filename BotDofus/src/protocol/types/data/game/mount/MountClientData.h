#ifndef MOUNTCLIENTDATA_H
#define MOUNTCLIENTDATA_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffectInteger.h"
#include "src/engines/io/network/utils/BooleanByteWrapper.h"
#include "src/engines/io/network/utils/FuncTree.h"

class MountClientData : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MountClientData(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MountClientData(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MountClientData(FuncTree tree);
  MountClientData();
  bool operator==(const MountClientData &compared);

  double id;
  uint model;
  QList<uint> ancestor;
  QList<uint> behaviors;
  QString name;
  bool sex;
  uint ownerId;
  double experience;
  double experienceForLevel;
  double experienceForNextLevel;
  uint level;
  bool isRideable;
  uint maxPods;
  bool isWild;
  uint stamina;
  uint staminaMax;
  uint maturity;
  uint maturityForAdult;
  uint energy;
  uint energyMax;
  int serenity;
  int aggressivityMax;
  uint serenityMax;
  uint love;
  uint loveMax;
  int fecondationTime;
  bool isFecondationReady;
  uint boostLimiter;
  double boostMax;
  int reproductionCount;
  uint reproductionCountMax;
  uint harnessGID;
  bool useHarnessColors;
  QList<QSharedPointer<ObjectEffectInteger>> effectList;

private:
  void deserializeByteBoxes(Reader *input);
  void _idFunc(Reader *input);
  void _modelFunc(Reader *input);
  void _ancestortreeFunc(Reader *input);
  void _ancestorFunc(Reader *input);
  void _behaviorstreeFunc(Reader *input);
  void _behaviorsFunc(Reader *input);
  void _nameFunc(Reader *input);
  void _ownerIdFunc(Reader *input);
  void _experienceFunc(Reader *input);
  void _experienceForLevelFunc(Reader *input);
  void _experienceForNextLevelFunc(Reader *input);
  void _levelFunc(Reader *input);
  void _maxPodsFunc(Reader *input);
  void _staminaFunc(Reader *input);
  void _staminaMaxFunc(Reader *input);
  void _maturityFunc(Reader *input);
  void _maturityForAdultFunc(Reader *input);
  void _energyFunc(Reader *input);
  void _energyMaxFunc(Reader *input);
  void _serenityFunc(Reader *input);
  void _aggressivityMaxFunc(Reader *input);
  void _serenityMaxFunc(Reader *input);
  void _loveFunc(Reader *input);
  void _loveMaxFunc(Reader *input);
  void _fecondationTimeFunc(Reader *input);
  void _boostLimiterFunc(Reader *input);
  void _boostMaxFunc(Reader *input);
  void _reproductionCountFunc(Reader *input);
  void _reproductionCountMaxFunc(Reader *input);
  void _harnessGIDFunc(Reader *input);
  void _effectListtreeFunc(Reader *input);
  void _effectListFunc(Reader *input);

  FuncTree _ancestortree;
  FuncTree _behaviorstree;
  FuncTree _effectListtree;
};

#endif // MOUNTCLIENTDATA_H