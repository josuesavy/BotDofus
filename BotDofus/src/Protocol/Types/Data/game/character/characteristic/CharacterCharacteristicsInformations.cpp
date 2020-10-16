#include "CharacterCharacteristicsInformations.h"

void CharacterCharacteristicsInformations::serialize(Writer *output)
{
  this->serializeAs_CharacterCharacteristicsInformations(output);
}

void CharacterCharacteristicsInformations::serializeAs_CharacterCharacteristicsInformations(Writer *output)
{
  if(this->experience < 0 || this->experience > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->experience << ") on element experience.";
  }
  output->writeVarLong((double)this->experience);
  if(this->experienceLevelFloor < 0 || this->experienceLevelFloor > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->experienceLevelFloor << ") on element experienceLevelFloor.";
  }
  output->writeVarLong((double)this->experienceLevelFloor);
  if(this->experienceNextLevelFloor < 0 || this->experienceNextLevelFloor > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->experienceNextLevelFloor << ") on element experienceNextLevelFloor.";
  }
  output->writeVarLong((double)this->experienceNextLevelFloor);
  if(this->experienceBonusLimit < 0 || this->experienceBonusLimit > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->experienceBonusLimit << ") on element experienceBonusLimit.";
  }
  output->writeVarLong((double)this->experienceBonusLimit);
  if(this->kamas < 0 || this->kamas > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->kamas << ") on element kamas.";
  }
  output->writeVarLong((double)this->kamas);
  if(this->statsPoints < 0)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->statsPoints << ") on element statsPoints.";
  }
  output->writeVarShort((int)this->statsPoints);
  if(this->additionnalPoints < 0)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->additionnalPoints << ") on element additionnalPoints.";
  }
  output->writeVarShort((int)this->additionnalPoints);
  if(this->spellsPoints < 0)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->spellsPoints << ") on element spellsPoints.";
  }
  output->writeVarShort((int)this->spellsPoints);
  this->alignmentInfos.serializeAs_ActorExtendedAlignmentInformations(output);
  if(this->lifePoints < 0)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->lifePoints << ") on element lifePoints.";
  }
  output->writeVarInt((int)this->lifePoints);
  if(this->maxLifePoints < 0)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->maxLifePoints << ") on element maxLifePoints.";
  }
  output->writeVarInt((int)this->maxLifePoints);
  if(this->energyPoints < 0)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->energyPoints << ") on element energyPoints.";
  }
  output->writeVarShort((int)this->energyPoints);
  if(this->maxEnergyPoints < 0)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->maxEnergyPoints << ") on element maxEnergyPoints.";
  }
  output->writeVarShort((int)this->maxEnergyPoints);
  output->writeVarShort((int)this->actionPointsCurrent);
  output->writeVarShort((int)this->movementPointsCurrent);
  this->initiative.serializeAs_CharacterBaseCharacteristic(output);
  this->prospecting.serializeAs_CharacterBaseCharacteristic(output);
  this->actionPoints.serializeAs_CharacterBaseCharacteristic(output);
  this->movementPoints.serializeAs_CharacterBaseCharacteristic(output);
  this->strength.serializeAs_CharacterBaseCharacteristic(output);
  this->vitality.serializeAs_CharacterBaseCharacteristic(output);
  this->wisdom.serializeAs_CharacterBaseCharacteristic(output);
  this->chance.serializeAs_CharacterBaseCharacteristic(output);
  this->agility.serializeAs_CharacterBaseCharacteristic(output);
  this->intelligence.serializeAs_CharacterBaseCharacteristic(output);
  this->range.serializeAs_CharacterBaseCharacteristic(output);
  this->summonableCreaturesBoost.serializeAs_CharacterBaseCharacteristic(output);
  this->reflect.serializeAs_CharacterBaseCharacteristic(output);
  this->criticalHit.serializeAs_CharacterBaseCharacteristic(output);
  if(this->criticalHitWeapon < 0)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->criticalHitWeapon << ") on element criticalHitWeapon.";
  }
  output->writeVarShort((int)this->criticalHitWeapon);
  this->criticalMiss.serializeAs_CharacterBaseCharacteristic(output);
  this->healBonus.serializeAs_CharacterBaseCharacteristic(output);
  this->allDamagesBonus.serializeAs_CharacterBaseCharacteristic(output);
  this->weaponDamagesBonusPercent.serializeAs_CharacterBaseCharacteristic(output);
  this->damagesBonusPercent.serializeAs_CharacterBaseCharacteristic(output);
  this->trapBonus.serializeAs_CharacterBaseCharacteristic(output);
  this->trapBonusPercent.serializeAs_CharacterBaseCharacteristic(output);
  this->glyphBonusPercent.serializeAs_CharacterBaseCharacteristic(output);
  this->runeBonusPercent.serializeAs_CharacterBaseCharacteristic(output);
  this->permanentDamagePercent.serializeAs_CharacterBaseCharacteristic(output);
  this->tackleBlock.serializeAs_CharacterBaseCharacteristic(output);
  this->tackleEvade.serializeAs_CharacterBaseCharacteristic(output);
  this->PAAttack.serializeAs_CharacterBaseCharacteristic(output);
  this->PMAttack.serializeAs_CharacterBaseCharacteristic(output);
  this->pushDamageBonus.serializeAs_CharacterBaseCharacteristic(output);
  this->criticalDamageBonus.serializeAs_CharacterBaseCharacteristic(output);
  this->neutralDamageBonus.serializeAs_CharacterBaseCharacteristic(output);
  this->earthDamageBonus.serializeAs_CharacterBaseCharacteristic(output);
  this->waterDamageBonus.serializeAs_CharacterBaseCharacteristic(output);
  this->airDamageBonus.serializeAs_CharacterBaseCharacteristic(output);
  this->fireDamageBonus.serializeAs_CharacterBaseCharacteristic(output);
  this->dodgePALostProbability.serializeAs_CharacterBaseCharacteristic(output);
  this->dodgePMLostProbability.serializeAs_CharacterBaseCharacteristic(output);
  this->neutralElementResistPercent.serializeAs_CharacterBaseCharacteristic(output);
  this->earthElementResistPercent.serializeAs_CharacterBaseCharacteristic(output);
  this->waterElementResistPercent.serializeAs_CharacterBaseCharacteristic(output);
  this->airElementResistPercent.serializeAs_CharacterBaseCharacteristic(output);
  this->fireElementResistPercent.serializeAs_CharacterBaseCharacteristic(output);
  this->neutralElementReduction.serializeAs_CharacterBaseCharacteristic(output);
  this->earthElementReduction.serializeAs_CharacterBaseCharacteristic(output);
  this->waterElementReduction.serializeAs_CharacterBaseCharacteristic(output);
  this->airElementReduction.serializeAs_CharacterBaseCharacteristic(output);
  this->fireElementReduction.serializeAs_CharacterBaseCharacteristic(output);
  this->pushDamageReduction.serializeAs_CharacterBaseCharacteristic(output);
  this->criticalDamageReduction.serializeAs_CharacterBaseCharacteristic(output);
  this->pvpNeutralElementResistPercent.serializeAs_CharacterBaseCharacteristic(output);
  this->pvpEarthElementResistPercent.serializeAs_CharacterBaseCharacteristic(output);
  this->pvpWaterElementResistPercent.serializeAs_CharacterBaseCharacteristic(output);
  this->pvpAirElementResistPercent.serializeAs_CharacterBaseCharacteristic(output);
  this->pvpFireElementResistPercent.serializeAs_CharacterBaseCharacteristic(output);
  this->pvpNeutralElementReduction.serializeAs_CharacterBaseCharacteristic(output);
  this->pvpEarthElementReduction.serializeAs_CharacterBaseCharacteristic(output);
  this->pvpWaterElementReduction.serializeAs_CharacterBaseCharacteristic(output);
  this->pvpAirElementReduction.serializeAs_CharacterBaseCharacteristic(output);
  this->pvpFireElementReduction.serializeAs_CharacterBaseCharacteristic(output);
  this->meleeDamageDonePercent.serializeAs_CharacterBaseCharacteristic(output);
  this->meleeDamageReceivedPercent.serializeAs_CharacterBaseCharacteristic(output);
  this->rangedDamageDonePercent.serializeAs_CharacterBaseCharacteristic(output);
  this->rangedDamageReceivedPercent.serializeAs_CharacterBaseCharacteristic(output);
  this->weaponDamageDonePercent.serializeAs_CharacterBaseCharacteristic(output);
  this->weaponDamageReceivedPercent.serializeAs_CharacterBaseCharacteristic(output);
  this->spellDamageDonePercent.serializeAs_CharacterBaseCharacteristic(output);
  this->spellDamageReceivedPercent.serializeAs_CharacterBaseCharacteristic(output);
  output->writeShort((short)this->spellModifications.size());
  for(uint _i84 = 0; _i84 < this->spellModifications.size(); _i84++)
  {
    (this->spellModifications[_i84]).serializeAs_CharacterSpellModification(output);
  }
  if(this->probationTime < 0)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->probationTime << ") on element probationTime.";
  }
  output->writeInt((int)this->probationTime);
}

void CharacterCharacteristicsInformations::deserialize(Reader *input)
{
  this->deserializeAs_CharacterCharacteristicsInformations(input);
}

void CharacterCharacteristicsInformations::deserializeAs_CharacterCharacteristicsInformations(Reader *input)
{
  CharacterSpellModification _item84 ;
  this->_experienceFunc(input);
  this->_experienceLevelFloorFunc(input);
  this->_experienceNextLevelFloorFunc(input);
  this->_experienceBonusLimitFunc(input);
  this->_kamasFunc(input);
  this->_statsPointsFunc(input);
  this->_additionnalPointsFunc(input);
  this->_spellsPointsFunc(input);
  this->alignmentInfos = ActorExtendedAlignmentInformations();
  this->alignmentInfos.deserialize(input);
  this->_lifePointsFunc(input);
  this->_maxLifePointsFunc(input);
  this->_energyPointsFunc(input);
  this->_maxEnergyPointsFunc(input);
  this->_actionPointsCurrentFunc(input);
  this->_movementPointsCurrentFunc(input);
  this->initiative = CharacterBaseCharacteristic();
  this->initiative.deserialize(input);
  this->prospecting = CharacterBaseCharacteristic();
  this->prospecting.deserialize(input);
  this->actionPoints = CharacterBaseCharacteristic();
  this->actionPoints.deserialize(input);
  this->movementPoints = CharacterBaseCharacteristic();
  this->movementPoints.deserialize(input);
  this->strength = CharacterBaseCharacteristic();
  this->strength.deserialize(input);
  this->vitality = CharacterBaseCharacteristic();
  this->vitality.deserialize(input);
  this->wisdom = CharacterBaseCharacteristic();
  this->wisdom.deserialize(input);
  this->chance = CharacterBaseCharacteristic();
  this->chance.deserialize(input);
  this->agility = CharacterBaseCharacteristic();
  this->agility.deserialize(input);
  this->intelligence = CharacterBaseCharacteristic();
  this->intelligence.deserialize(input);
  this->range = CharacterBaseCharacteristic();
  this->range.deserialize(input);
  this->summonableCreaturesBoost = CharacterBaseCharacteristic();
  this->summonableCreaturesBoost.deserialize(input);
  this->reflect = CharacterBaseCharacteristic();
  this->reflect.deserialize(input);
  this->criticalHit = CharacterBaseCharacteristic();
  this->criticalHit.deserialize(input);
  this->_criticalHitWeaponFunc(input);
  this->criticalMiss = CharacterBaseCharacteristic();
  this->criticalMiss.deserialize(input);
  this->healBonus = CharacterBaseCharacteristic();
  this->healBonus.deserialize(input);
  this->allDamagesBonus = CharacterBaseCharacteristic();
  this->allDamagesBonus.deserialize(input);
  this->weaponDamagesBonusPercent = CharacterBaseCharacteristic();
  this->weaponDamagesBonusPercent.deserialize(input);
  this->damagesBonusPercent = CharacterBaseCharacteristic();
  this->damagesBonusPercent.deserialize(input);
  this->trapBonus = CharacterBaseCharacteristic();
  this->trapBonus.deserialize(input);
  this->trapBonusPercent = CharacterBaseCharacteristic();
  this->trapBonusPercent.deserialize(input);
  this->glyphBonusPercent = CharacterBaseCharacteristic();
  this->glyphBonusPercent.deserialize(input);
  this->runeBonusPercent = CharacterBaseCharacteristic();
  this->runeBonusPercent.deserialize(input);
  this->permanentDamagePercent = CharacterBaseCharacteristic();
  this->permanentDamagePercent.deserialize(input);
  this->tackleBlock = CharacterBaseCharacteristic();
  this->tackleBlock.deserialize(input);
  this->tackleEvade = CharacterBaseCharacteristic();
  this->tackleEvade.deserialize(input);
  this->PAAttack = CharacterBaseCharacteristic();
  this->PAAttack.deserialize(input);
  this->PMAttack = CharacterBaseCharacteristic();
  this->PMAttack.deserialize(input);
  this->pushDamageBonus = CharacterBaseCharacteristic();
  this->pushDamageBonus.deserialize(input);
  this->criticalDamageBonus = CharacterBaseCharacteristic();
  this->criticalDamageBonus.deserialize(input);
  this->neutralDamageBonus = CharacterBaseCharacteristic();
  this->neutralDamageBonus.deserialize(input);
  this->earthDamageBonus = CharacterBaseCharacteristic();
  this->earthDamageBonus.deserialize(input);
  this->waterDamageBonus = CharacterBaseCharacteristic();
  this->waterDamageBonus.deserialize(input);
  this->airDamageBonus = CharacterBaseCharacteristic();
  this->airDamageBonus.deserialize(input);
  this->fireDamageBonus = CharacterBaseCharacteristic();
  this->fireDamageBonus.deserialize(input);
  this->dodgePALostProbability = CharacterBaseCharacteristic();
  this->dodgePALostProbability.deserialize(input);
  this->dodgePMLostProbability = CharacterBaseCharacteristic();
  this->dodgePMLostProbability.deserialize(input);
  this->neutralElementResistPercent = CharacterBaseCharacteristic();
  this->neutralElementResistPercent.deserialize(input);
  this->earthElementResistPercent = CharacterBaseCharacteristic();
  this->earthElementResistPercent.deserialize(input);
  this->waterElementResistPercent = CharacterBaseCharacteristic();
  this->waterElementResistPercent.deserialize(input);
  this->airElementResistPercent = CharacterBaseCharacteristic();
  this->airElementResistPercent.deserialize(input);
  this->fireElementResistPercent = CharacterBaseCharacteristic();
  this->fireElementResistPercent.deserialize(input);
  this->neutralElementReduction = CharacterBaseCharacteristic();
  this->neutralElementReduction.deserialize(input);
  this->earthElementReduction = CharacterBaseCharacteristic();
  this->earthElementReduction.deserialize(input);
  this->waterElementReduction = CharacterBaseCharacteristic();
  this->waterElementReduction.deserialize(input);
  this->airElementReduction = CharacterBaseCharacteristic();
  this->airElementReduction.deserialize(input);
  this->fireElementReduction = CharacterBaseCharacteristic();
  this->fireElementReduction.deserialize(input);
  this->pushDamageReduction = CharacterBaseCharacteristic();
  this->pushDamageReduction.deserialize(input);
  this->criticalDamageReduction = CharacterBaseCharacteristic();
  this->criticalDamageReduction.deserialize(input);
  this->pvpNeutralElementResistPercent = CharacterBaseCharacteristic();
  this->pvpNeutralElementResistPercent.deserialize(input);
  this->pvpEarthElementResistPercent = CharacterBaseCharacteristic();
  this->pvpEarthElementResistPercent.deserialize(input);
  this->pvpWaterElementResistPercent = CharacterBaseCharacteristic();
  this->pvpWaterElementResistPercent.deserialize(input);
  this->pvpAirElementResistPercent = CharacterBaseCharacteristic();
  this->pvpAirElementResistPercent.deserialize(input);
  this->pvpFireElementResistPercent = CharacterBaseCharacteristic();
  this->pvpFireElementResistPercent.deserialize(input);
  this->pvpNeutralElementReduction = CharacterBaseCharacteristic();
  this->pvpNeutralElementReduction.deserialize(input);
  this->pvpEarthElementReduction = CharacterBaseCharacteristic();
  this->pvpEarthElementReduction.deserialize(input);
  this->pvpWaterElementReduction = CharacterBaseCharacteristic();
  this->pvpWaterElementReduction.deserialize(input);
  this->pvpAirElementReduction = CharacterBaseCharacteristic();
  this->pvpAirElementReduction.deserialize(input);
  this->pvpFireElementReduction = CharacterBaseCharacteristic();
  this->pvpFireElementReduction.deserialize(input);
  this->meleeDamageDonePercent = CharacterBaseCharacteristic();
  this->meleeDamageDonePercent.deserialize(input);
  this->meleeDamageReceivedPercent = CharacterBaseCharacteristic();
  this->meleeDamageReceivedPercent.deserialize(input);
  this->rangedDamageDonePercent = CharacterBaseCharacteristic();
  this->rangedDamageDonePercent.deserialize(input);
  this->rangedDamageReceivedPercent = CharacterBaseCharacteristic();
  this->rangedDamageReceivedPercent.deserialize(input);
  this->weaponDamageDonePercent = CharacterBaseCharacteristic();
  this->weaponDamageDonePercent.deserialize(input);
  this->weaponDamageReceivedPercent = CharacterBaseCharacteristic();
  this->weaponDamageReceivedPercent.deserialize(input);
  this->spellDamageDonePercent = CharacterBaseCharacteristic();
  this->spellDamageDonePercent.deserialize(input);
  this->spellDamageReceivedPercent = CharacterBaseCharacteristic();
  this->spellDamageReceivedPercent.deserialize(input);
  uint _spellModificationsLen = input->readUShort();
  for(uint _i84 = 0; _i84 < _spellModificationsLen; _i84++)
  {
    _item84 = CharacterSpellModification();
    _item84.deserialize(input);
    this->spellModifications.append(_item84);
  }
  this->_probationTimeFunc(input);
}

void CharacterCharacteristicsInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterCharacteristicsInformations(tree);
}

void CharacterCharacteristicsInformations::deserializeAsyncAs_CharacterCharacteristicsInformations(FuncTree tree)
{
  tree.addChild(std::bind(&CharacterCharacteristicsInformations::_experienceFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCharacteristicsInformations::_experienceLevelFloorFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCharacteristicsInformations::_experienceNextLevelFloorFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCharacteristicsInformations::_experienceBonusLimitFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCharacteristicsInformations::_kamasFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCharacteristicsInformations::_statsPointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCharacteristicsInformations::_additionnalPointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCharacteristicsInformations::_spellsPointsFunc, this, std::placeholders::_1));
  this->_alignmentInfostree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_alignmentInfostreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCharacteristicsInformations::_lifePointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCharacteristicsInformations::_maxLifePointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCharacteristicsInformations::_energyPointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCharacteristicsInformations::_maxEnergyPointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCharacteristicsInformations::_actionPointsCurrentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCharacteristicsInformations::_movementPointsCurrentFunc, this, std::placeholders::_1));
  this->_initiativetree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_initiativetreeFunc, this, std::placeholders::_1));
  this->_prospectingtree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_prospectingtreeFunc, this, std::placeholders::_1));
  this->_actionPointstree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_actionPointstreeFunc, this, std::placeholders::_1));
  this->_movementPointstree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_movementPointstreeFunc, this, std::placeholders::_1));
  this->_strengthtree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_strengthtreeFunc, this, std::placeholders::_1));
  this->_vitalitytree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_vitalitytreeFunc, this, std::placeholders::_1));
  this->_wisdomtree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_wisdomtreeFunc, this, std::placeholders::_1));
  this->_chancetree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_chancetreeFunc, this, std::placeholders::_1));
  this->_agilitytree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_agilitytreeFunc, this, std::placeholders::_1));
  this->_intelligencetree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_intelligencetreeFunc, this, std::placeholders::_1));
  this->_rangetree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_rangetreeFunc, this, std::placeholders::_1));
  this->_summonableCreaturesBoosttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_summonableCreaturesBoosttreeFunc, this, std::placeholders::_1));
  this->_reflecttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_reflecttreeFunc, this, std::placeholders::_1));
  this->_criticalHittree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_criticalHittreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCharacteristicsInformations::_criticalHitWeaponFunc, this, std::placeholders::_1));
  this->_criticalMisstree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_criticalMisstreeFunc, this, std::placeholders::_1));
  this->_healBonustree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_healBonustreeFunc, this, std::placeholders::_1));
  this->_allDamagesBonustree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_allDamagesBonustreeFunc, this, std::placeholders::_1));
  this->_weaponDamagesBonusPercenttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_weaponDamagesBonusPercenttreeFunc, this, std::placeholders::_1));
  this->_damagesBonusPercenttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_damagesBonusPercenttreeFunc, this, std::placeholders::_1));
  this->_trapBonustree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_trapBonustreeFunc, this, std::placeholders::_1));
  this->_trapBonusPercenttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_trapBonusPercenttreeFunc, this, std::placeholders::_1));
  this->_glyphBonusPercenttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_glyphBonusPercenttreeFunc, this, std::placeholders::_1));
  this->_runeBonusPercenttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_runeBonusPercenttreeFunc, this, std::placeholders::_1));
  this->_permanentDamagePercenttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_permanentDamagePercenttreeFunc, this, std::placeholders::_1));
  this->_tackleBlocktree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_tackleBlocktreeFunc, this, std::placeholders::_1));
  this->_tackleEvadetree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_tackleEvadetreeFunc, this, std::placeholders::_1));
  this->_PAAttacktree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_PAAttacktreeFunc, this, std::placeholders::_1));
  this->_PMAttacktree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_PMAttacktreeFunc, this, std::placeholders::_1));
  this->_pushDamageBonustree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_pushDamageBonustreeFunc, this, std::placeholders::_1));
  this->_criticalDamageBonustree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_criticalDamageBonustreeFunc, this, std::placeholders::_1));
  this->_neutralDamageBonustree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_neutralDamageBonustreeFunc, this, std::placeholders::_1));
  this->_earthDamageBonustree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_earthDamageBonustreeFunc, this, std::placeholders::_1));
  this->_waterDamageBonustree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_waterDamageBonustreeFunc, this, std::placeholders::_1));
  this->_airDamageBonustree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_airDamageBonustreeFunc, this, std::placeholders::_1));
  this->_fireDamageBonustree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_fireDamageBonustreeFunc, this, std::placeholders::_1));
  this->_dodgePALostProbabilitytree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_dodgePALostProbabilitytreeFunc, this, std::placeholders::_1));
  this->_dodgePMLostProbabilitytree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_dodgePMLostProbabilitytreeFunc, this, std::placeholders::_1));
  this->_neutralElementResistPercenttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_neutralElementResistPercenttreeFunc, this, std::placeholders::_1));
  this->_earthElementResistPercenttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_earthElementResistPercenttreeFunc, this, std::placeholders::_1));
  this->_waterElementResistPercenttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_waterElementResistPercenttreeFunc, this, std::placeholders::_1));
  this->_airElementResistPercenttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_airElementResistPercenttreeFunc, this, std::placeholders::_1));
  this->_fireElementResistPercenttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_fireElementResistPercenttreeFunc, this, std::placeholders::_1));
  this->_neutralElementReductiontree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_neutralElementReductiontreeFunc, this, std::placeholders::_1));
  this->_earthElementReductiontree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_earthElementReductiontreeFunc, this, std::placeholders::_1));
  this->_waterElementReductiontree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_waterElementReductiontreeFunc, this, std::placeholders::_1));
  this->_airElementReductiontree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_airElementReductiontreeFunc, this, std::placeholders::_1));
  this->_fireElementReductiontree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_fireElementReductiontreeFunc, this, std::placeholders::_1));
  this->_pushDamageReductiontree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_pushDamageReductiontreeFunc, this, std::placeholders::_1));
  this->_criticalDamageReductiontree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_criticalDamageReductiontreeFunc, this, std::placeholders::_1));
  this->_pvpNeutralElementResistPercenttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_pvpNeutralElementResistPercenttreeFunc, this, std::placeholders::_1));
  this->_pvpEarthElementResistPercenttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_pvpEarthElementResistPercenttreeFunc, this, std::placeholders::_1));
  this->_pvpWaterElementResistPercenttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_pvpWaterElementResistPercenttreeFunc, this, std::placeholders::_1));
  this->_pvpAirElementResistPercenttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_pvpAirElementResistPercenttreeFunc, this, std::placeholders::_1));
  this->_pvpFireElementResistPercenttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_pvpFireElementResistPercenttreeFunc, this, std::placeholders::_1));
  this->_pvpNeutralElementReductiontree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_pvpNeutralElementReductiontreeFunc, this, std::placeholders::_1));
  this->_pvpEarthElementReductiontree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_pvpEarthElementReductiontreeFunc, this, std::placeholders::_1));
  this->_pvpWaterElementReductiontree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_pvpWaterElementReductiontreeFunc, this, std::placeholders::_1));
  this->_pvpAirElementReductiontree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_pvpAirElementReductiontreeFunc, this, std::placeholders::_1));
  this->_pvpFireElementReductiontree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_pvpFireElementReductiontreeFunc, this, std::placeholders::_1));
  this->_meleeDamageDonePercenttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_meleeDamageDonePercenttreeFunc, this, std::placeholders::_1));
  this->_meleeDamageReceivedPercenttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_meleeDamageReceivedPercenttreeFunc, this, std::placeholders::_1));
  this->_rangedDamageDonePercenttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_rangedDamageDonePercenttreeFunc, this, std::placeholders::_1));
  this->_rangedDamageReceivedPercenttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_rangedDamageReceivedPercenttreeFunc, this, std::placeholders::_1));
  this->_weaponDamageDonePercenttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_weaponDamageDonePercenttreeFunc, this, std::placeholders::_1));
  this->_weaponDamageReceivedPercenttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_weaponDamageReceivedPercenttreeFunc, this, std::placeholders::_1));
  this->_spellDamageDonePercenttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_spellDamageDonePercenttreeFunc, this, std::placeholders::_1));
  this->_spellDamageReceivedPercenttree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_spellDamageReceivedPercenttreeFunc, this, std::placeholders::_1));
  this->_spellModificationstree = tree.addChild(std::bind(&CharacterCharacteristicsInformations::_spellModificationstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCharacteristicsInformations::_probationTimeFunc, this, std::placeholders::_1));
}

void CharacterCharacteristicsInformations::_experienceFunc(Reader *input)
{
  this->experience = input->readVarUhLong();
  if(this->experience < 0 || this->experience > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->experience << ") on element of CharacterCharacteristicsInformations.experience.";
  }
}

void CharacterCharacteristicsInformations::_experienceLevelFloorFunc(Reader *input)
{
  this->experienceLevelFloor = input->readVarUhLong();
  if(this->experienceLevelFloor < 0 || this->experienceLevelFloor > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->experienceLevelFloor << ") on element of CharacterCharacteristicsInformations.experienceLevelFloor.";
  }
}

void CharacterCharacteristicsInformations::_experienceNextLevelFloorFunc(Reader *input)
{
  this->experienceNextLevelFloor = input->readVarUhLong();
  if(this->experienceNextLevelFloor < 0 || this->experienceNextLevelFloor > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->experienceNextLevelFloor << ") on element of CharacterCharacteristicsInformations.experienceNextLevelFloor.";
  }
}

void CharacterCharacteristicsInformations::_experienceBonusLimitFunc(Reader *input)
{
  this->experienceBonusLimit = input->readVarUhLong();
  if(this->experienceBonusLimit < 0 || this->experienceBonusLimit > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->experienceBonusLimit << ") on element of CharacterCharacteristicsInformations.experienceBonusLimit.";
  }
}

void CharacterCharacteristicsInformations::_kamasFunc(Reader *input)
{
  this->kamas = input->readVarUhLong();
  if(this->kamas < 0 || this->kamas > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->kamas << ") on element of CharacterCharacteristicsInformations.kamas.";
  }
}

void CharacterCharacteristicsInformations::_statsPointsFunc(Reader *input)
{
  this->statsPoints = input->readVarUhShort();
  if(this->statsPoints < 0)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->statsPoints << ") on element of CharacterCharacteristicsInformations.statsPoints.";
  }
}

void CharacterCharacteristicsInformations::_additionnalPointsFunc(Reader *input)
{
  this->additionnalPoints = input->readVarUhShort();
  if(this->additionnalPoints < 0)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->additionnalPoints << ") on element of CharacterCharacteristicsInformations.additionnalPoints.";
  }
}

void CharacterCharacteristicsInformations::_spellsPointsFunc(Reader *input)
{
  this->spellsPoints = input->readVarUhShort();
  if(this->spellsPoints < 0)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->spellsPoints << ") on element of CharacterCharacteristicsInformations.spellsPoints.";
  }
}

void CharacterCharacteristicsInformations::_alignmentInfostreeFunc(Reader *input)
{
  this->alignmentInfos = ActorExtendedAlignmentInformations();
  this->alignmentInfos.deserializeAsync(this->_alignmentInfostree);
}

void CharacterCharacteristicsInformations::_lifePointsFunc(Reader *input)
{
  this->lifePoints = input->readVarUhInt();
  if(this->lifePoints < 0)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->lifePoints << ") on element of CharacterCharacteristicsInformations.lifePoints.";
  }
}

void CharacterCharacteristicsInformations::_maxLifePointsFunc(Reader *input)
{
  this->maxLifePoints = input->readVarUhInt();
  if(this->maxLifePoints < 0)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->maxLifePoints << ") on element of CharacterCharacteristicsInformations.maxLifePoints.";
  }
}

void CharacterCharacteristicsInformations::_energyPointsFunc(Reader *input)
{
  this->energyPoints = input->readVarUhShort();
  if(this->energyPoints < 0)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->energyPoints << ") on element of CharacterCharacteristicsInformations.energyPoints.";
  }
}

void CharacterCharacteristicsInformations::_maxEnergyPointsFunc(Reader *input)
{
  this->maxEnergyPoints = input->readVarUhShort();
  if(this->maxEnergyPoints < 0)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->maxEnergyPoints << ") on element of CharacterCharacteristicsInformations.maxEnergyPoints.";
  }
}

void CharacterCharacteristicsInformations::_actionPointsCurrentFunc(Reader *input)
{
  this->actionPointsCurrent = input->readVarShort();
}

void CharacterCharacteristicsInformations::_movementPointsCurrentFunc(Reader *input)
{
  this->movementPointsCurrent = input->readVarShort();
}

void CharacterCharacteristicsInformations::_initiativetreeFunc(Reader *input)
{
  this->initiative = CharacterBaseCharacteristic();
  this->initiative.deserializeAsync(this->_initiativetree);
}

void CharacterCharacteristicsInformations::_prospectingtreeFunc(Reader *input)
{
  this->prospecting = CharacterBaseCharacteristic();
  this->prospecting.deserializeAsync(this->_prospectingtree);
}

void CharacterCharacteristicsInformations::_actionPointstreeFunc(Reader *input)
{
  this->actionPoints = CharacterBaseCharacteristic();
  this->actionPoints.deserializeAsync(this->_actionPointstree);
}

void CharacterCharacteristicsInformations::_movementPointstreeFunc(Reader *input)
{
  this->movementPoints = CharacterBaseCharacteristic();
  this->movementPoints.deserializeAsync(this->_movementPointstree);
}

void CharacterCharacteristicsInformations::_strengthtreeFunc(Reader *input)
{
  this->strength = CharacterBaseCharacteristic();
  this->strength.deserializeAsync(this->_strengthtree);
}

void CharacterCharacteristicsInformations::_vitalitytreeFunc(Reader *input)
{
  this->vitality = CharacterBaseCharacteristic();
  this->vitality.deserializeAsync(this->_vitalitytree);
}

void CharacterCharacteristicsInformations::_wisdomtreeFunc(Reader *input)
{
  this->wisdom = CharacterBaseCharacteristic();
  this->wisdom.deserializeAsync(this->_wisdomtree);
}

void CharacterCharacteristicsInformations::_chancetreeFunc(Reader *input)
{
  this->chance = CharacterBaseCharacteristic();
  this->chance.deserializeAsync(this->_chancetree);
}

void CharacterCharacteristicsInformations::_agilitytreeFunc(Reader *input)
{
  this->agility = CharacterBaseCharacteristic();
  this->agility.deserializeAsync(this->_agilitytree);
}

void CharacterCharacteristicsInformations::_intelligencetreeFunc(Reader *input)
{
  this->intelligence = CharacterBaseCharacteristic();
  this->intelligence.deserializeAsync(this->_intelligencetree);
}

void CharacterCharacteristicsInformations::_rangetreeFunc(Reader *input)
{
  this->range = CharacterBaseCharacteristic();
  this->range.deserializeAsync(this->_rangetree);
}

void CharacterCharacteristicsInformations::_summonableCreaturesBoosttreeFunc(Reader *input)
{
  this->summonableCreaturesBoost = CharacterBaseCharacteristic();
  this->summonableCreaturesBoost.deserializeAsync(this->_summonableCreaturesBoosttree);
}

void CharacterCharacteristicsInformations::_reflecttreeFunc(Reader *input)
{
  this->reflect = CharacterBaseCharacteristic();
  this->reflect.deserializeAsync(this->_reflecttree);
}

void CharacterCharacteristicsInformations::_criticalHittreeFunc(Reader *input)
{
  this->criticalHit = CharacterBaseCharacteristic();
  this->criticalHit.deserializeAsync(this->_criticalHittree);
}

void CharacterCharacteristicsInformations::_criticalHitWeaponFunc(Reader *input)
{
  this->criticalHitWeapon = input->readVarUhShort();
  if(this->criticalHitWeapon < 0)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->criticalHitWeapon << ") on element of CharacterCharacteristicsInformations.criticalHitWeapon.";
  }
}

void CharacterCharacteristicsInformations::_criticalMisstreeFunc(Reader *input)
{
  this->criticalMiss = CharacterBaseCharacteristic();
  this->criticalMiss.deserializeAsync(this->_criticalMisstree);
}

void CharacterCharacteristicsInformations::_healBonustreeFunc(Reader *input)
{
  this->healBonus = CharacterBaseCharacteristic();
  this->healBonus.deserializeAsync(this->_healBonustree);
}

void CharacterCharacteristicsInformations::_allDamagesBonustreeFunc(Reader *input)
{
  this->allDamagesBonus = CharacterBaseCharacteristic();
  this->allDamagesBonus.deserializeAsync(this->_allDamagesBonustree);
}

void CharacterCharacteristicsInformations::_weaponDamagesBonusPercenttreeFunc(Reader *input)
{
  this->weaponDamagesBonusPercent = CharacterBaseCharacteristic();
  this->weaponDamagesBonusPercent.deserializeAsync(this->_weaponDamagesBonusPercenttree);
}

void CharacterCharacteristicsInformations::_damagesBonusPercenttreeFunc(Reader *input)
{
  this->damagesBonusPercent = CharacterBaseCharacteristic();
  this->damagesBonusPercent.deserializeAsync(this->_damagesBonusPercenttree);
}

void CharacterCharacteristicsInformations::_trapBonustreeFunc(Reader *input)
{
  this->trapBonus = CharacterBaseCharacteristic();
  this->trapBonus.deserializeAsync(this->_trapBonustree);
}

void CharacterCharacteristicsInformations::_trapBonusPercenttreeFunc(Reader *input)
{
  this->trapBonusPercent = CharacterBaseCharacteristic();
  this->trapBonusPercent.deserializeAsync(this->_trapBonusPercenttree);
}

void CharacterCharacteristicsInformations::_glyphBonusPercenttreeFunc(Reader *input)
{
  this->glyphBonusPercent = CharacterBaseCharacteristic();
  this->glyphBonusPercent.deserializeAsync(this->_glyphBonusPercenttree);
}

void CharacterCharacteristicsInformations::_runeBonusPercenttreeFunc(Reader *input)
{
  this->runeBonusPercent = CharacterBaseCharacteristic();
  this->runeBonusPercent.deserializeAsync(this->_runeBonusPercenttree);
}

void CharacterCharacteristicsInformations::_permanentDamagePercenttreeFunc(Reader *input)
{
  this->permanentDamagePercent = CharacterBaseCharacteristic();
  this->permanentDamagePercent.deserializeAsync(this->_permanentDamagePercenttree);
}

void CharacterCharacteristicsInformations::_tackleBlocktreeFunc(Reader *input)
{
  this->tackleBlock = CharacterBaseCharacteristic();
  this->tackleBlock.deserializeAsync(this->_tackleBlocktree);
}

void CharacterCharacteristicsInformations::_tackleEvadetreeFunc(Reader *input)
{
  this->tackleEvade = CharacterBaseCharacteristic();
  this->tackleEvade.deserializeAsync(this->_tackleEvadetree);
}

void CharacterCharacteristicsInformations::_PAAttacktreeFunc(Reader *input)
{
  this->PAAttack = CharacterBaseCharacteristic();
  this->PAAttack.deserializeAsync(this->_PAAttacktree);
}

void CharacterCharacteristicsInformations::_PMAttacktreeFunc(Reader *input)
{
  this->PMAttack = CharacterBaseCharacteristic();
  this->PMAttack.deserializeAsync(this->_PMAttacktree);
}

void CharacterCharacteristicsInformations::_pushDamageBonustreeFunc(Reader *input)
{
  this->pushDamageBonus = CharacterBaseCharacteristic();
  this->pushDamageBonus.deserializeAsync(this->_pushDamageBonustree);
}

void CharacterCharacteristicsInformations::_criticalDamageBonustreeFunc(Reader *input)
{
  this->criticalDamageBonus = CharacterBaseCharacteristic();
  this->criticalDamageBonus.deserializeAsync(this->_criticalDamageBonustree);
}

void CharacterCharacteristicsInformations::_neutralDamageBonustreeFunc(Reader *input)
{
  this->neutralDamageBonus = CharacterBaseCharacteristic();
  this->neutralDamageBonus.deserializeAsync(this->_neutralDamageBonustree);
}

void CharacterCharacteristicsInformations::_earthDamageBonustreeFunc(Reader *input)
{
  this->earthDamageBonus = CharacterBaseCharacteristic();
  this->earthDamageBonus.deserializeAsync(this->_earthDamageBonustree);
}

void CharacterCharacteristicsInformations::_waterDamageBonustreeFunc(Reader *input)
{
  this->waterDamageBonus = CharacterBaseCharacteristic();
  this->waterDamageBonus.deserializeAsync(this->_waterDamageBonustree);
}

void CharacterCharacteristicsInformations::_airDamageBonustreeFunc(Reader *input)
{
  this->airDamageBonus = CharacterBaseCharacteristic();
  this->airDamageBonus.deserializeAsync(this->_airDamageBonustree);
}

void CharacterCharacteristicsInformations::_fireDamageBonustreeFunc(Reader *input)
{
  this->fireDamageBonus = CharacterBaseCharacteristic();
  this->fireDamageBonus.deserializeAsync(this->_fireDamageBonustree);
}

void CharacterCharacteristicsInformations::_dodgePALostProbabilitytreeFunc(Reader *input)
{
  this->dodgePALostProbability = CharacterBaseCharacteristic();
  this->dodgePALostProbability.deserializeAsync(this->_dodgePALostProbabilitytree);
}

void CharacterCharacteristicsInformations::_dodgePMLostProbabilitytreeFunc(Reader *input)
{
  this->dodgePMLostProbability = CharacterBaseCharacteristic();
  this->dodgePMLostProbability.deserializeAsync(this->_dodgePMLostProbabilitytree);
}

void CharacterCharacteristicsInformations::_neutralElementResistPercenttreeFunc(Reader *input)
{
  this->neutralElementResistPercent = CharacterBaseCharacteristic();
  this->neutralElementResistPercent.deserializeAsync(this->_neutralElementResistPercenttree);
}

void CharacterCharacteristicsInformations::_earthElementResistPercenttreeFunc(Reader *input)
{
  this->earthElementResistPercent = CharacterBaseCharacteristic();
  this->earthElementResistPercent.deserializeAsync(this->_earthElementResistPercenttree);
}

void CharacterCharacteristicsInformations::_waterElementResistPercenttreeFunc(Reader *input)
{
  this->waterElementResistPercent = CharacterBaseCharacteristic();
  this->waterElementResistPercent.deserializeAsync(this->_waterElementResistPercenttree);
}

void CharacterCharacteristicsInformations::_airElementResistPercenttreeFunc(Reader *input)
{
  this->airElementResistPercent = CharacterBaseCharacteristic();
  this->airElementResistPercent.deserializeAsync(this->_airElementResistPercenttree);
}

void CharacterCharacteristicsInformations::_fireElementResistPercenttreeFunc(Reader *input)
{
  this->fireElementResistPercent = CharacterBaseCharacteristic();
  this->fireElementResistPercent.deserializeAsync(this->_fireElementResistPercenttree);
}

void CharacterCharacteristicsInformations::_neutralElementReductiontreeFunc(Reader *input)
{
  this->neutralElementReduction = CharacterBaseCharacteristic();
  this->neutralElementReduction.deserializeAsync(this->_neutralElementReductiontree);
}

void CharacterCharacteristicsInformations::_earthElementReductiontreeFunc(Reader *input)
{
  this->earthElementReduction = CharacterBaseCharacteristic();
  this->earthElementReduction.deserializeAsync(this->_earthElementReductiontree);
}

void CharacterCharacteristicsInformations::_waterElementReductiontreeFunc(Reader *input)
{
  this->waterElementReduction = CharacterBaseCharacteristic();
  this->waterElementReduction.deserializeAsync(this->_waterElementReductiontree);
}

void CharacterCharacteristicsInformations::_airElementReductiontreeFunc(Reader *input)
{
  this->airElementReduction = CharacterBaseCharacteristic();
  this->airElementReduction.deserializeAsync(this->_airElementReductiontree);
}

void CharacterCharacteristicsInformations::_fireElementReductiontreeFunc(Reader *input)
{
  this->fireElementReduction = CharacterBaseCharacteristic();
  this->fireElementReduction.deserializeAsync(this->_fireElementReductiontree);
}

void CharacterCharacteristicsInformations::_pushDamageReductiontreeFunc(Reader *input)
{
  this->pushDamageReduction = CharacterBaseCharacteristic();
  this->pushDamageReduction.deserializeAsync(this->_pushDamageReductiontree);
}

void CharacterCharacteristicsInformations::_criticalDamageReductiontreeFunc(Reader *input)
{
  this->criticalDamageReduction = CharacterBaseCharacteristic();
  this->criticalDamageReduction.deserializeAsync(this->_criticalDamageReductiontree);
}

void CharacterCharacteristicsInformations::_pvpNeutralElementResistPercenttreeFunc(Reader *input)
{
  this->pvpNeutralElementResistPercent = CharacterBaseCharacteristic();
  this->pvpNeutralElementResistPercent.deserializeAsync(this->_pvpNeutralElementResistPercenttree);
}

void CharacterCharacteristicsInformations::_pvpEarthElementResistPercenttreeFunc(Reader *input)
{
  this->pvpEarthElementResistPercent = CharacterBaseCharacteristic();
  this->pvpEarthElementResistPercent.deserializeAsync(this->_pvpEarthElementResistPercenttree);
}

void CharacterCharacteristicsInformations::_pvpWaterElementResistPercenttreeFunc(Reader *input)
{
  this->pvpWaterElementResistPercent = CharacterBaseCharacteristic();
  this->pvpWaterElementResistPercent.deserializeAsync(this->_pvpWaterElementResistPercenttree);
}

void CharacterCharacteristicsInformations::_pvpAirElementResistPercenttreeFunc(Reader *input)
{
  this->pvpAirElementResistPercent = CharacterBaseCharacteristic();
  this->pvpAirElementResistPercent.deserializeAsync(this->_pvpAirElementResistPercenttree);
}

void CharacterCharacteristicsInformations::_pvpFireElementResistPercenttreeFunc(Reader *input)
{
  this->pvpFireElementResistPercent = CharacterBaseCharacteristic();
  this->pvpFireElementResistPercent.deserializeAsync(this->_pvpFireElementResistPercenttree);
}

void CharacterCharacteristicsInformations::_pvpNeutralElementReductiontreeFunc(Reader *input)
{
  this->pvpNeutralElementReduction = CharacterBaseCharacteristic();
  this->pvpNeutralElementReduction.deserializeAsync(this->_pvpNeutralElementReductiontree);
}

void CharacterCharacteristicsInformations::_pvpEarthElementReductiontreeFunc(Reader *input)
{
  this->pvpEarthElementReduction = CharacterBaseCharacteristic();
  this->pvpEarthElementReduction.deserializeAsync(this->_pvpEarthElementReductiontree);
}

void CharacterCharacteristicsInformations::_pvpWaterElementReductiontreeFunc(Reader *input)
{
  this->pvpWaterElementReduction = CharacterBaseCharacteristic();
  this->pvpWaterElementReduction.deserializeAsync(this->_pvpWaterElementReductiontree);
}

void CharacterCharacteristicsInformations::_pvpAirElementReductiontreeFunc(Reader *input)
{
  this->pvpAirElementReduction = CharacterBaseCharacteristic();
  this->pvpAirElementReduction.deserializeAsync(this->_pvpAirElementReductiontree);
}

void CharacterCharacteristicsInformations::_pvpFireElementReductiontreeFunc(Reader *input)
{
  this->pvpFireElementReduction = CharacterBaseCharacteristic();
  this->pvpFireElementReduction.deserializeAsync(this->_pvpFireElementReductiontree);
}

void CharacterCharacteristicsInformations::_meleeDamageDonePercenttreeFunc(Reader *input)
{
  this->meleeDamageDonePercent = CharacterBaseCharacteristic();
  this->meleeDamageDonePercent.deserializeAsync(this->_meleeDamageDonePercenttree);
}

void CharacterCharacteristicsInformations::_meleeDamageReceivedPercenttreeFunc(Reader *input)
{
  this->meleeDamageReceivedPercent = CharacterBaseCharacteristic();
  this->meleeDamageReceivedPercent.deserializeAsync(this->_meleeDamageReceivedPercenttree);
}

void CharacterCharacteristicsInformations::_rangedDamageDonePercenttreeFunc(Reader *input)
{
  this->rangedDamageDonePercent = CharacterBaseCharacteristic();
  this->rangedDamageDonePercent.deserializeAsync(this->_rangedDamageDonePercenttree);
}

void CharacterCharacteristicsInformations::_rangedDamageReceivedPercenttreeFunc(Reader *input)
{
  this->rangedDamageReceivedPercent = CharacterBaseCharacteristic();
  this->rangedDamageReceivedPercent.deserializeAsync(this->_rangedDamageReceivedPercenttree);
}

void CharacterCharacteristicsInformations::_weaponDamageDonePercenttreeFunc(Reader *input)
{
  this->weaponDamageDonePercent = CharacterBaseCharacteristic();
  this->weaponDamageDonePercent.deserializeAsync(this->_weaponDamageDonePercenttree);
}

void CharacterCharacteristicsInformations::_weaponDamageReceivedPercenttreeFunc(Reader *input)
{
  this->weaponDamageReceivedPercent = CharacterBaseCharacteristic();
  this->weaponDamageReceivedPercent.deserializeAsync(this->_weaponDamageReceivedPercenttree);
}

void CharacterCharacteristicsInformations::_spellDamageDonePercenttreeFunc(Reader *input)
{
  this->spellDamageDonePercent = CharacterBaseCharacteristic();
  this->spellDamageDonePercent.deserializeAsync(this->_spellDamageDonePercenttree);
}

void CharacterCharacteristicsInformations::_spellDamageReceivedPercenttreeFunc(Reader *input)
{
  this->spellDamageReceivedPercent = CharacterBaseCharacteristic();
  this->spellDamageReceivedPercent.deserializeAsync(this->_spellDamageReceivedPercenttree);
}

void CharacterCharacteristicsInformations::_spellModificationstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_spellModificationstree.addChild(std::bind(&CharacterCharacteristicsInformations::_spellModificationsFunc, this, std::placeholders::_1));
  }
}

void CharacterCharacteristicsInformations::_spellModificationsFunc(Reader *input)
{
  CharacterSpellModification _item = CharacterSpellModification();
  _item.deserialize(input);
  this->spellModifications.append(_item);
}

void CharacterCharacteristicsInformations::_probationTimeFunc(Reader *input)
{
  this->probationTime = input->readInt();
  if(this->probationTime < 0)
  {
    qDebug()<<"ERREUR - CharacterCharacteristicsInformations -"<<"Forbidden value (" << this->probationTime << ") on element of CharacterCharacteristicsInformations.probationTime.";
  }
}

CharacterCharacteristicsInformations::CharacterCharacteristicsInformations()
{
  m_types<<ClassEnum::CHARACTERCHARACTERISTICSINFORMATIONS;
}

bool CharacterCharacteristicsInformations::operator==(const CharacterCharacteristicsInformations &compared)
{
  if(experience == compared.experience)
  if(experienceLevelFloor == compared.experienceLevelFloor)
  if(experienceNextLevelFloor == compared.experienceNextLevelFloor)
  if(experienceBonusLimit == compared.experienceBonusLimit)
  if(kamas == compared.kamas)
  if(statsPoints == compared.statsPoints)
  if(additionnalPoints == compared.additionnalPoints)
  if(spellsPoints == compared.spellsPoints)
  if(alignmentInfos == compared.alignmentInfos)
  if(lifePoints == compared.lifePoints)
  if(maxLifePoints == compared.maxLifePoints)
  if(energyPoints == compared.energyPoints)
  if(maxEnergyPoints == compared.maxEnergyPoints)
  if(actionPointsCurrent == compared.actionPointsCurrent)
  if(movementPointsCurrent == compared.movementPointsCurrent)
  if(initiative == compared.initiative)
  if(prospecting == compared.prospecting)
  if(actionPoints == compared.actionPoints)
  if(movementPoints == compared.movementPoints)
  if(strength == compared.strength)
  if(vitality == compared.vitality)
  if(wisdom == compared.wisdom)
  if(chance == compared.chance)
  if(agility == compared.agility)
  if(intelligence == compared.intelligence)
  if(range == compared.range)
  if(summonableCreaturesBoost == compared.summonableCreaturesBoost)
  if(reflect == compared.reflect)
  if(criticalHit == compared.criticalHit)
  if(criticalHitWeapon == compared.criticalHitWeapon)
  if(criticalMiss == compared.criticalMiss)
  if(healBonus == compared.healBonus)
  if(allDamagesBonus == compared.allDamagesBonus)
  if(weaponDamagesBonusPercent == compared.weaponDamagesBonusPercent)
  if(damagesBonusPercent == compared.damagesBonusPercent)
  if(trapBonus == compared.trapBonus)
  if(trapBonusPercent == compared.trapBonusPercent)
  if(glyphBonusPercent == compared.glyphBonusPercent)
  if(runeBonusPercent == compared.runeBonusPercent)
  if(permanentDamagePercent == compared.permanentDamagePercent)
  if(tackleBlock == compared.tackleBlock)
  if(tackleEvade == compared.tackleEvade)
  if(PAAttack == compared.PAAttack)
  if(PMAttack == compared.PMAttack)
  if(pushDamageBonus == compared.pushDamageBonus)
  if(criticalDamageBonus == compared.criticalDamageBonus)
  if(neutralDamageBonus == compared.neutralDamageBonus)
  if(earthDamageBonus == compared.earthDamageBonus)
  if(waterDamageBonus == compared.waterDamageBonus)
  if(airDamageBonus == compared.airDamageBonus)
  if(fireDamageBonus == compared.fireDamageBonus)
  if(dodgePALostProbability == compared.dodgePALostProbability)
  if(dodgePMLostProbability == compared.dodgePMLostProbability)
  if(neutralElementResistPercent == compared.neutralElementResistPercent)
  if(earthElementResistPercent == compared.earthElementResistPercent)
  if(waterElementResistPercent == compared.waterElementResistPercent)
  if(airElementResistPercent == compared.airElementResistPercent)
  if(fireElementResistPercent == compared.fireElementResistPercent)
  if(neutralElementReduction == compared.neutralElementReduction)
  if(earthElementReduction == compared.earthElementReduction)
  if(waterElementReduction == compared.waterElementReduction)
  if(airElementReduction == compared.airElementReduction)
  if(fireElementReduction == compared.fireElementReduction)
  if(pushDamageReduction == compared.pushDamageReduction)
  if(criticalDamageReduction == compared.criticalDamageReduction)
  if(pvpNeutralElementResistPercent == compared.pvpNeutralElementResistPercent)
  if(pvpEarthElementResistPercent == compared.pvpEarthElementResistPercent)
  if(pvpWaterElementResistPercent == compared.pvpWaterElementResistPercent)
  if(pvpAirElementResistPercent == compared.pvpAirElementResistPercent)
  if(pvpFireElementResistPercent == compared.pvpFireElementResistPercent)
  if(pvpNeutralElementReduction == compared.pvpNeutralElementReduction)
  if(pvpEarthElementReduction == compared.pvpEarthElementReduction)
  if(pvpWaterElementReduction == compared.pvpWaterElementReduction)
  if(pvpAirElementReduction == compared.pvpAirElementReduction)
  if(pvpFireElementReduction == compared.pvpFireElementReduction)
  if(meleeDamageDonePercent == compared.meleeDamageDonePercent)
  if(meleeDamageReceivedPercent == compared.meleeDamageReceivedPercent)
  if(rangedDamageDonePercent == compared.rangedDamageDonePercent)
  if(rangedDamageReceivedPercent == compared.rangedDamageReceivedPercent)
  if(weaponDamageDonePercent == compared.weaponDamageDonePercent)
  if(weaponDamageReceivedPercent == compared.weaponDamageReceivedPercent)
  if(spellDamageDonePercent == compared.spellDamageDonePercent)
  if(spellDamageReceivedPercent == compared.spellDamageReceivedPercent)
  if(spellModifications == compared.spellModifications)
  if(probationTime == compared.probationTime)
  if(_alignmentInfostree == compared._alignmentInfostree)
  if(_initiativetree == compared._initiativetree)
  if(_prospectingtree == compared._prospectingtree)
  if(_actionPointstree == compared._actionPointstree)
  if(_movementPointstree == compared._movementPointstree)
  if(_strengthtree == compared._strengthtree)
  if(_vitalitytree == compared._vitalitytree)
  if(_wisdomtree == compared._wisdomtree)
  if(_chancetree == compared._chancetree)
  if(_agilitytree == compared._agilitytree)
  if(_intelligencetree == compared._intelligencetree)
  if(_rangetree == compared._rangetree)
  if(_summonableCreaturesBoosttree == compared._summonableCreaturesBoosttree)
  if(_reflecttree == compared._reflecttree)
  if(_criticalHittree == compared._criticalHittree)
  if(_criticalMisstree == compared._criticalMisstree)
  if(_healBonustree == compared._healBonustree)
  if(_allDamagesBonustree == compared._allDamagesBonustree)
  if(_weaponDamagesBonusPercenttree == compared._weaponDamagesBonusPercenttree)
  if(_damagesBonusPercenttree == compared._damagesBonusPercenttree)
  if(_trapBonustree == compared._trapBonustree)
  if(_trapBonusPercenttree == compared._trapBonusPercenttree)
  if(_glyphBonusPercenttree == compared._glyphBonusPercenttree)
  if(_runeBonusPercenttree == compared._runeBonusPercenttree)
  if(_permanentDamagePercenttree == compared._permanentDamagePercenttree)
  if(_tackleBlocktree == compared._tackleBlocktree)
  if(_tackleEvadetree == compared._tackleEvadetree)
  if(_PAAttacktree == compared._PAAttacktree)
  if(_PMAttacktree == compared._PMAttacktree)
  if(_pushDamageBonustree == compared._pushDamageBonustree)
  if(_criticalDamageBonustree == compared._criticalDamageBonustree)
  if(_neutralDamageBonustree == compared._neutralDamageBonustree)
  if(_earthDamageBonustree == compared._earthDamageBonustree)
  if(_waterDamageBonustree == compared._waterDamageBonustree)
  if(_airDamageBonustree == compared._airDamageBonustree)
  if(_fireDamageBonustree == compared._fireDamageBonustree)
  if(_dodgePALostProbabilitytree == compared._dodgePALostProbabilitytree)
  if(_dodgePMLostProbabilitytree == compared._dodgePMLostProbabilitytree)
  if(_neutralElementResistPercenttree == compared._neutralElementResistPercenttree)
  if(_earthElementResistPercenttree == compared._earthElementResistPercenttree)
  if(_waterElementResistPercenttree == compared._waterElementResistPercenttree)
  if(_airElementResistPercenttree == compared._airElementResistPercenttree)
  if(_fireElementResistPercenttree == compared._fireElementResistPercenttree)
  if(_neutralElementReductiontree == compared._neutralElementReductiontree)
  if(_earthElementReductiontree == compared._earthElementReductiontree)
  if(_waterElementReductiontree == compared._waterElementReductiontree)
  if(_airElementReductiontree == compared._airElementReductiontree)
  if(_fireElementReductiontree == compared._fireElementReductiontree)
  if(_pushDamageReductiontree == compared._pushDamageReductiontree)
  if(_criticalDamageReductiontree == compared._criticalDamageReductiontree)
  if(_pvpNeutralElementResistPercenttree == compared._pvpNeutralElementResistPercenttree)
  if(_pvpEarthElementResistPercenttree == compared._pvpEarthElementResistPercenttree)
  if(_pvpWaterElementResistPercenttree == compared._pvpWaterElementResistPercenttree)
  if(_pvpAirElementResistPercenttree == compared._pvpAirElementResistPercenttree)
  if(_pvpFireElementResistPercenttree == compared._pvpFireElementResistPercenttree)
  if(_pvpNeutralElementReductiontree == compared._pvpNeutralElementReductiontree)
  if(_pvpEarthElementReductiontree == compared._pvpEarthElementReductiontree)
  if(_pvpWaterElementReductiontree == compared._pvpWaterElementReductiontree)
  if(_pvpAirElementReductiontree == compared._pvpAirElementReductiontree)
  if(_pvpFireElementReductiontree == compared._pvpFireElementReductiontree)
  if(_meleeDamageDonePercenttree == compared._meleeDamageDonePercenttree)
  if(_meleeDamageReceivedPercenttree == compared._meleeDamageReceivedPercenttree)
  if(_rangedDamageDonePercenttree == compared._rangedDamageDonePercenttree)
  if(_rangedDamageReceivedPercenttree == compared._rangedDamageReceivedPercenttree)
  if(_weaponDamageDonePercenttree == compared._weaponDamageDonePercenttree)
  if(_weaponDamageReceivedPercenttree == compared._weaponDamageReceivedPercenttree)
  if(_spellDamageDonePercenttree == compared._spellDamageDonePercenttree)
  if(_spellDamageReceivedPercenttree == compared._spellDamageReceivedPercenttree)
  if(_spellModificationstree == compared._spellModificationstree)
  return true;
  
  return false;
}

