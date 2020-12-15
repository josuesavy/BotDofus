#ifndef GAMEFIGHTMINIMALSTATS_H
#define GAMEFIGHTMINIMALSTATS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GameFightMinimalStats : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightMinimalStats(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightMinimalStats(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightMinimalStats(FuncTree tree);
  GameFightMinimalStats();
  bool operator==(const GameFightMinimalStats &compared);

  uint lifePoints;
  uint maxLifePoints;
  uint baseMaxLifePoints;
  uint permanentDamagePercent;
  uint shieldPoints;
  int actionPoints;
  int maxActionPoints;
  int movementPoints;
  int maxMovementPoints;
  double summoner;
  bool summoned;
  int neutralElementResistPercent;
  int earthElementResistPercent;
  int waterElementResistPercent;
  int airElementResistPercent;
  int fireElementResistPercent;
  int neutralElementReduction;
  int earthElementReduction;
  int waterElementReduction;
  int airElementReduction;
  int fireElementReduction;
  int criticalDamageFixedResist;
  int pushDamageFixedResist;
  int pvpNeutralElementResistPercent;
  int pvpEarthElementResistPercent;
  int pvpWaterElementResistPercent;
  int pvpAirElementResistPercent;
  int pvpFireElementResistPercent;
  int pvpNeutralElementReduction;
  int pvpEarthElementReduction;
  int pvpWaterElementReduction;
  int pvpAirElementReduction;
  int pvpFireElementReduction;
  uint dodgePALostProbability;
  uint dodgePMLostProbability;
  int tackleBlock;
  int tackleEvade;
  int fixedDamageReflection;
  uint invisibilityState;
  uint meleeDamageReceivedPercent;
  uint rangedDamageReceivedPercent;
  uint weaponDamageReceivedPercent;
  uint spellDamageReceivedPercent;

private:
  void _lifePointsFunc(Reader *input);
  void _maxLifePointsFunc(Reader *input);
  void _baseMaxLifePointsFunc(Reader *input);
  void _permanentDamagePercentFunc(Reader *input);
  void _shieldPointsFunc(Reader *input);
  void _actionPointsFunc(Reader *input);
  void _maxActionPointsFunc(Reader *input);
  void _movementPointsFunc(Reader *input);
  void _maxMovementPointsFunc(Reader *input);
  void _summonerFunc(Reader *input);
  void _summonedFunc(Reader *input);
  void _neutralElementResistPercentFunc(Reader *input);
  void _earthElementResistPercentFunc(Reader *input);
  void _waterElementResistPercentFunc(Reader *input);
  void _airElementResistPercentFunc(Reader *input);
  void _fireElementResistPercentFunc(Reader *input);
  void _neutralElementReductionFunc(Reader *input);
  void _earthElementReductionFunc(Reader *input);
  void _waterElementReductionFunc(Reader *input);
  void _airElementReductionFunc(Reader *input);
  void _fireElementReductionFunc(Reader *input);
  void _criticalDamageFixedResistFunc(Reader *input);
  void _pushDamageFixedResistFunc(Reader *input);
  void _pvpNeutralElementResistPercentFunc(Reader *input);
  void _pvpEarthElementResistPercentFunc(Reader *input);
  void _pvpWaterElementResistPercentFunc(Reader *input);
  void _pvpAirElementResistPercentFunc(Reader *input);
  void _pvpFireElementResistPercentFunc(Reader *input);
  void _pvpNeutralElementReductionFunc(Reader *input);
  void _pvpEarthElementReductionFunc(Reader *input);
  void _pvpWaterElementReductionFunc(Reader *input);
  void _pvpAirElementReductionFunc(Reader *input);
  void _pvpFireElementReductionFunc(Reader *input);
  void _dodgePALostProbabilityFunc(Reader *input);
  void _dodgePMLostProbabilityFunc(Reader *input);
  void _tackleBlockFunc(Reader *input);
  void _tackleEvadeFunc(Reader *input);
  void _fixedDamageReflectionFunc(Reader *input);
  void _invisibilityStateFunc(Reader *input);
  void _meleeDamageReceivedPercentFunc(Reader *input);
  void _rangedDamageReceivedPercentFunc(Reader *input);
  void _weaponDamageReceivedPercentFunc(Reader *input);
  void _spellDamageReceivedPercentFunc(Reader *input);
};

#endif // GAMEFIGHTMINIMALSTATS_H