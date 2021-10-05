#ifndef MONSTERBONUSCHARACTERISTICSDATA_H
#define MONSTERBONUSCHARACTERISTICSDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class MonsterBonusCharacteristicsData : public AbstractGameData
{
public:
  int getLifePoints() const;
  int getStrength() const;
  int getWisdom() const;
  int getChance() const;
  int getAgility() const;
  int getIntelligence() const;
  int getEarthResistance() const;
  int getFireResistance() const;
  int getWaterResistance() const;
  int getAirResistance() const;
  int getNeutralResistance() const;
  int getTackleEvade() const;
  int getTackleBlock() const;
  int getBonusEarthDamage() const;
  int getBonusFireDamage() const;
  int getBonusWaterDamage() const;
  int getBonusAirDamage() const;
  int getAPRemoval() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_lifePoints;
  int m_strength;
  int m_wisdom;
  int m_chance;
  int m_agility;
  int m_intelligence;
  int m_earthResistance;
  int m_fireResistance;
  int m_waterResistance;
  int m_airResistance;
  int m_neutralResistance;
  int m_tackleEvade;
  int m_tackleBlock;
  int m_bonusEarthDamage;
  int m_bonusFireDamage;
  int m_bonusWaterDamage;
  int m_bonusAirDamage;
  int m_APRemoval;
};

#endif // MONSTERBONUSCHARACTERISTICSDATA_H