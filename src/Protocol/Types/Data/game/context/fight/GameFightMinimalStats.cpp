#include "GameFightMinimalStats.h"

void GameFightMinimalStats::serialize(Writer *output)
{
  this->serializeAs_GameFightMinimalStats(output);
}

void GameFightMinimalStats::serializeAs_GameFightMinimalStats(Writer *output)
{
  if(this->lifePoints < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->lifePoints << ") on element lifePoints.";
  }
  output->writeVarInt((int)this->lifePoints);
  if(this->maxLifePoints < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->maxLifePoints << ") on element maxLifePoints.";
  }
  output->writeVarInt((int)this->maxLifePoints);
  if(this->baseMaxLifePoints < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->baseMaxLifePoints << ") on element baseMaxLifePoints.";
  }
  output->writeVarInt((int)this->baseMaxLifePoints);
  if(this->permanentDamagePercent < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->permanentDamagePercent << ") on element permanentDamagePercent.";
  }
  output->writeVarInt((int)this->permanentDamagePercent);
  if(this->shieldPoints < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->shieldPoints << ") on element shieldPoints.";
  }
  output->writeVarInt((int)this->shieldPoints);
  output->writeVarShort((int)this->actionPoints);
  output->writeVarShort((int)this->maxActionPoints);
  output->writeVarShort((int)this->movementPoints);
  output->writeVarShort((int)this->maxMovementPoints);
  if(this->summoner < -9.007199254740992E15 || this->summoner > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->summoner << ") on element summoner.";
  }
  output->writeDouble(this->summoner);
  output->writeBool(this->summoned);
  output->writeVarShort((int)this->neutralElementResistPercent);
  output->writeVarShort((int)this->earthElementResistPercent);
  output->writeVarShort((int)this->waterElementResistPercent);
  output->writeVarShort((int)this->airElementResistPercent);
  output->writeVarShort((int)this->fireElementResistPercent);
  output->writeVarShort((int)this->neutralElementReduction);
  output->writeVarShort((int)this->earthElementReduction);
  output->writeVarShort((int)this->waterElementReduction);
  output->writeVarShort((int)this->airElementReduction);
  output->writeVarShort((int)this->fireElementReduction);
  output->writeVarShort((int)this->criticalDamageFixedResist);
  output->writeVarShort((int)this->pushDamageFixedResist);
  output->writeVarShort((int)this->pvpNeutralElementResistPercent);
  output->writeVarShort((int)this->pvpEarthElementResistPercent);
  output->writeVarShort((int)this->pvpWaterElementResistPercent);
  output->writeVarShort((int)this->pvpAirElementResistPercent);
  output->writeVarShort((int)this->pvpFireElementResistPercent);
  output->writeVarShort((int)this->pvpNeutralElementReduction);
  output->writeVarShort((int)this->pvpEarthElementReduction);
  output->writeVarShort((int)this->pvpWaterElementReduction);
  output->writeVarShort((int)this->pvpAirElementReduction);
  output->writeVarShort((int)this->pvpFireElementReduction);
  if(this->dodgePALostProbability < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->dodgePALostProbability << ") on element dodgePALostProbability.";
  }
  output->writeVarShort((int)this->dodgePALostProbability);
  if(this->dodgePMLostProbability < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->dodgePMLostProbability << ") on element dodgePMLostProbability.";
  }
  output->writeVarShort((int)this->dodgePMLostProbability);
  output->writeVarShort((int)this->tackleBlock);
  output->writeVarShort((int)this->tackleEvade);
  output->writeVarShort((int)this->fixedDamageReflection);
  output->writeByte(this->invisibilityState);
  if(this->meleeDamageReceivedPercent < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->meleeDamageReceivedPercent << ") on element meleeDamageReceivedPercent.";
  }
  output->writeVarShort((int)this->meleeDamageReceivedPercent);
  if(this->rangedDamageReceivedPercent < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->rangedDamageReceivedPercent << ") on element rangedDamageReceivedPercent.";
  }
  output->writeVarShort((int)this->rangedDamageReceivedPercent);
  if(this->weaponDamageReceivedPercent < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->weaponDamageReceivedPercent << ") on element weaponDamageReceivedPercent.";
  }
  output->writeVarShort((int)this->weaponDamageReceivedPercent);
  if(this->spellDamageReceivedPercent < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->spellDamageReceivedPercent << ") on element spellDamageReceivedPercent.";
  }
  output->writeVarShort((int)this->spellDamageReceivedPercent);
}

void GameFightMinimalStats::deserialize(Reader *input)
{
  this->deserializeAs_GameFightMinimalStats(input);
}

void GameFightMinimalStats::deserializeAs_GameFightMinimalStats(Reader *input)
{
  this->_lifePointsFunc(input);
  this->_maxLifePointsFunc(input);
  this->_baseMaxLifePointsFunc(input);
  this->_permanentDamagePercentFunc(input);
  this->_shieldPointsFunc(input);
  this->_actionPointsFunc(input);
  this->_maxActionPointsFunc(input);
  this->_movementPointsFunc(input);
  this->_maxMovementPointsFunc(input);
  this->_summonerFunc(input);
  this->_summonedFunc(input);
  this->_neutralElementResistPercentFunc(input);
  this->_earthElementResistPercentFunc(input);
  this->_waterElementResistPercentFunc(input);
  this->_airElementResistPercentFunc(input);
  this->_fireElementResistPercentFunc(input);
  this->_neutralElementReductionFunc(input);
  this->_earthElementReductionFunc(input);
  this->_waterElementReductionFunc(input);
  this->_airElementReductionFunc(input);
  this->_fireElementReductionFunc(input);
  this->_criticalDamageFixedResistFunc(input);
  this->_pushDamageFixedResistFunc(input);
  this->_pvpNeutralElementResistPercentFunc(input);
  this->_pvpEarthElementResistPercentFunc(input);
  this->_pvpWaterElementResistPercentFunc(input);
  this->_pvpAirElementResistPercentFunc(input);
  this->_pvpFireElementResistPercentFunc(input);
  this->_pvpNeutralElementReductionFunc(input);
  this->_pvpEarthElementReductionFunc(input);
  this->_pvpWaterElementReductionFunc(input);
  this->_pvpAirElementReductionFunc(input);
  this->_pvpFireElementReductionFunc(input);
  this->_dodgePALostProbabilityFunc(input);
  this->_dodgePMLostProbabilityFunc(input);
  this->_tackleBlockFunc(input);
  this->_tackleEvadeFunc(input);
  this->_fixedDamageReflectionFunc(input);
  this->_invisibilityStateFunc(input);
  this->_meleeDamageReceivedPercentFunc(input);
  this->_rangedDamageReceivedPercentFunc(input);
  this->_weaponDamageReceivedPercentFunc(input);
  this->_spellDamageReceivedPercentFunc(input);
}

void GameFightMinimalStats::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightMinimalStats(tree);
}

void GameFightMinimalStats::deserializeAsyncAs_GameFightMinimalStats(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightMinimalStats::_lifePointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_maxLifePointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_baseMaxLifePointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_permanentDamagePercentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_shieldPointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_actionPointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_maxActionPointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_movementPointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_maxMovementPointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_summonerFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_summonedFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_neutralElementResistPercentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_earthElementResistPercentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_waterElementResistPercentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_airElementResistPercentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_fireElementResistPercentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_neutralElementReductionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_earthElementReductionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_waterElementReductionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_airElementReductionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_fireElementReductionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_criticalDamageFixedResistFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_pushDamageFixedResistFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_pvpNeutralElementResistPercentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_pvpEarthElementResistPercentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_pvpWaterElementResistPercentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_pvpAirElementResistPercentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_pvpFireElementResistPercentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_pvpNeutralElementReductionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_pvpEarthElementReductionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_pvpWaterElementReductionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_pvpAirElementReductionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_pvpFireElementReductionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_dodgePALostProbabilityFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_dodgePMLostProbabilityFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_tackleBlockFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_tackleEvadeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_fixedDamageReflectionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_invisibilityStateFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_meleeDamageReceivedPercentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_rangedDamageReceivedPercentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_weaponDamageReceivedPercentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMinimalStats::_spellDamageReceivedPercentFunc, this, std::placeholders::_1));
}

void GameFightMinimalStats::_lifePointsFunc(Reader *input)
{
  this->lifePoints = input->readVarUhInt();
  if(this->lifePoints < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->lifePoints << ") on element of GameFightMinimalStats.lifePoints.";
  }
}

void GameFightMinimalStats::_maxLifePointsFunc(Reader *input)
{
  this->maxLifePoints = input->readVarUhInt();
  if(this->maxLifePoints < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->maxLifePoints << ") on element of GameFightMinimalStats.maxLifePoints.";
  }
}

void GameFightMinimalStats::_baseMaxLifePointsFunc(Reader *input)
{
  this->baseMaxLifePoints = input->readVarUhInt();
  if(this->baseMaxLifePoints < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->baseMaxLifePoints << ") on element of GameFightMinimalStats.baseMaxLifePoints.";
  }
}

void GameFightMinimalStats::_permanentDamagePercentFunc(Reader *input)
{
  this->permanentDamagePercent = input->readVarUhInt();
  if(this->permanentDamagePercent < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->permanentDamagePercent << ") on element of GameFightMinimalStats.permanentDamagePercent.";
  }
}

void GameFightMinimalStats::_shieldPointsFunc(Reader *input)
{
  this->shieldPoints = input->readVarUhInt();
  if(this->shieldPoints < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->shieldPoints << ") on element of GameFightMinimalStats.shieldPoints.";
  }
}

void GameFightMinimalStats::_actionPointsFunc(Reader *input)
{
  this->actionPoints = input->readVarShort();
}

void GameFightMinimalStats::_maxActionPointsFunc(Reader *input)
{
  this->maxActionPoints = input->readVarShort();
}

void GameFightMinimalStats::_movementPointsFunc(Reader *input)
{
  this->movementPoints = input->readVarShort();
}

void GameFightMinimalStats::_maxMovementPointsFunc(Reader *input)
{
  this->maxMovementPoints = input->readVarShort();
}

void GameFightMinimalStats::_summonerFunc(Reader *input)
{
  this->summoner = input->readDouble();
  if(this->summoner < -9.007199254740992E15 || this->summoner > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->summoner << ") on element of GameFightMinimalStats.summoner.";
  }
}

void GameFightMinimalStats::_summonedFunc(Reader *input)
{
  this->summoned = input->readBool();
}

void GameFightMinimalStats::_neutralElementResistPercentFunc(Reader *input)
{
  this->neutralElementResistPercent = input->readVarShort();
}

void GameFightMinimalStats::_earthElementResistPercentFunc(Reader *input)
{
  this->earthElementResistPercent = input->readVarShort();
}

void GameFightMinimalStats::_waterElementResistPercentFunc(Reader *input)
{
  this->waterElementResistPercent = input->readVarShort();
}

void GameFightMinimalStats::_airElementResistPercentFunc(Reader *input)
{
  this->airElementResistPercent = input->readVarShort();
}

void GameFightMinimalStats::_fireElementResistPercentFunc(Reader *input)
{
  this->fireElementResistPercent = input->readVarShort();
}

void GameFightMinimalStats::_neutralElementReductionFunc(Reader *input)
{
  this->neutralElementReduction = input->readVarShort();
}

void GameFightMinimalStats::_earthElementReductionFunc(Reader *input)
{
  this->earthElementReduction = input->readVarShort();
}

void GameFightMinimalStats::_waterElementReductionFunc(Reader *input)
{
  this->waterElementReduction = input->readVarShort();
}

void GameFightMinimalStats::_airElementReductionFunc(Reader *input)
{
  this->airElementReduction = input->readVarShort();
}

void GameFightMinimalStats::_fireElementReductionFunc(Reader *input)
{
  this->fireElementReduction = input->readVarShort();
}

void GameFightMinimalStats::_criticalDamageFixedResistFunc(Reader *input)
{
  this->criticalDamageFixedResist = input->readVarShort();
}

void GameFightMinimalStats::_pushDamageFixedResistFunc(Reader *input)
{
  this->pushDamageFixedResist = input->readVarShort();
}

void GameFightMinimalStats::_pvpNeutralElementResistPercentFunc(Reader *input)
{
  this->pvpNeutralElementResistPercent = input->readVarShort();
}

void GameFightMinimalStats::_pvpEarthElementResistPercentFunc(Reader *input)
{
  this->pvpEarthElementResistPercent = input->readVarShort();
}

void GameFightMinimalStats::_pvpWaterElementResistPercentFunc(Reader *input)
{
  this->pvpWaterElementResistPercent = input->readVarShort();
}

void GameFightMinimalStats::_pvpAirElementResistPercentFunc(Reader *input)
{
  this->pvpAirElementResistPercent = input->readVarShort();
}

void GameFightMinimalStats::_pvpFireElementResistPercentFunc(Reader *input)
{
  this->pvpFireElementResistPercent = input->readVarShort();
}

void GameFightMinimalStats::_pvpNeutralElementReductionFunc(Reader *input)
{
  this->pvpNeutralElementReduction = input->readVarShort();
}

void GameFightMinimalStats::_pvpEarthElementReductionFunc(Reader *input)
{
  this->pvpEarthElementReduction = input->readVarShort();
}

void GameFightMinimalStats::_pvpWaterElementReductionFunc(Reader *input)
{
  this->pvpWaterElementReduction = input->readVarShort();
}

void GameFightMinimalStats::_pvpAirElementReductionFunc(Reader *input)
{
  this->pvpAirElementReduction = input->readVarShort();
}

void GameFightMinimalStats::_pvpFireElementReductionFunc(Reader *input)
{
  this->pvpFireElementReduction = input->readVarShort();
}

void GameFightMinimalStats::_dodgePALostProbabilityFunc(Reader *input)
{
  this->dodgePALostProbability = input->readVarUhShort();
  if(this->dodgePALostProbability < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->dodgePALostProbability << ") on element of GameFightMinimalStats.dodgePALostProbability.";
  }
}

void GameFightMinimalStats::_dodgePMLostProbabilityFunc(Reader *input)
{
  this->dodgePMLostProbability = input->readVarUhShort();
  if(this->dodgePMLostProbability < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->dodgePMLostProbability << ") on element of GameFightMinimalStats.dodgePMLostProbability.";
  }
}

void GameFightMinimalStats::_tackleBlockFunc(Reader *input)
{
  this->tackleBlock = input->readVarShort();
}

void GameFightMinimalStats::_tackleEvadeFunc(Reader *input)
{
  this->tackleEvade = input->readVarShort();
}

void GameFightMinimalStats::_fixedDamageReflectionFunc(Reader *input)
{
  this->fixedDamageReflection = input->readVarShort();
}

void GameFightMinimalStats::_invisibilityStateFunc(Reader *input)
{
  this->invisibilityState = input->readByte();
  if(this->invisibilityState < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->invisibilityState << ") on element of GameFightMinimalStats.invisibilityState.";
  }
}

void GameFightMinimalStats::_meleeDamageReceivedPercentFunc(Reader *input)
{
  this->meleeDamageReceivedPercent = input->readVarUhShort();
  if(this->meleeDamageReceivedPercent < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->meleeDamageReceivedPercent << ") on element of GameFightMinimalStats.meleeDamageReceivedPercent.";
  }
}

void GameFightMinimalStats::_rangedDamageReceivedPercentFunc(Reader *input)
{
  this->rangedDamageReceivedPercent = input->readVarUhShort();
  if(this->rangedDamageReceivedPercent < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->rangedDamageReceivedPercent << ") on element of GameFightMinimalStats.rangedDamageReceivedPercent.";
  }
}

void GameFightMinimalStats::_weaponDamageReceivedPercentFunc(Reader *input)
{
  this->weaponDamageReceivedPercent = input->readVarUhShort();
  if(this->weaponDamageReceivedPercent < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->weaponDamageReceivedPercent << ") on element of GameFightMinimalStats.weaponDamageReceivedPercent.";
  }
}

void GameFightMinimalStats::_spellDamageReceivedPercentFunc(Reader *input)
{
  this->spellDamageReceivedPercent = input->readVarUhShort();
  if(this->spellDamageReceivedPercent < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStats -"<<"Forbidden value (" << this->spellDamageReceivedPercent << ") on element of GameFightMinimalStats.spellDamageReceivedPercent.";
  }
}

GameFightMinimalStats::GameFightMinimalStats()
{
  m_types<<ClassEnum::GAMEFIGHTMINIMALSTATS;
}

bool GameFightMinimalStats::operator==(const GameFightMinimalStats &compared)
{
  if(lifePoints == compared.lifePoints)
  if(maxLifePoints == compared.maxLifePoints)
  if(baseMaxLifePoints == compared.baseMaxLifePoints)
  if(permanentDamagePercent == compared.permanentDamagePercent)
  if(shieldPoints == compared.shieldPoints)
  if(actionPoints == compared.actionPoints)
  if(maxActionPoints == compared.maxActionPoints)
  if(movementPoints == compared.movementPoints)
  if(maxMovementPoints == compared.maxMovementPoints)
  if(summoner == compared.summoner)
  if(summoned == compared.summoned)
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
  if(criticalDamageFixedResist == compared.criticalDamageFixedResist)
  if(pushDamageFixedResist == compared.pushDamageFixedResist)
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
  if(dodgePALostProbability == compared.dodgePALostProbability)
  if(dodgePMLostProbability == compared.dodgePMLostProbability)
  if(tackleBlock == compared.tackleBlock)
  if(tackleEvade == compared.tackleEvade)
  if(fixedDamageReflection == compared.fixedDamageReflection)
  if(invisibilityState == compared.invisibilityState)
  if(meleeDamageReceivedPercent == compared.meleeDamageReceivedPercent)
  if(rangedDamageReceivedPercent == compared.rangedDamageReceivedPercent)
  if(weaponDamageReceivedPercent == compared.weaponDamageReceivedPercent)
  if(spellDamageReceivedPercent == compared.spellDamageReceivedPercent)
  return true;
  
  return false;
}

