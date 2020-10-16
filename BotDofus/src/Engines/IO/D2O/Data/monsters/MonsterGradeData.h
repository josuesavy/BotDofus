#ifndef MONSTERGRADEDATA_H
#define MONSTERGRADEDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"
#include "src/Engines/IO/D2O/Data/monsters/MonsterBonusCharacteristicsData.h"

class MonsterGradeData : public AbstractGameData
{
public:
  uint getGrade() const;
  int getMonsterId() const;
  uint getLevel() const;
  int getVitality() const;
  int getPaDodge() const;
  int getPmDodge() const;
  int getWisdom() const;
  int getEarthResistance() const;
  int getAirResistance() const;
  int getFireResistance() const;
  int getWaterResistance() const;
  int getNeutralResistance() const;
  int getGradeXp() const;
  int getLifePoints() const;
  int getActionPoints() const;
  int getMovementPoints() const;
  int getDamageReflect() const;
  uint getHiddenLevel() const;
  int getStrength() const;
  int getIntelligence() const;
  int getChance() const;
  int getAgility() const;
  int getBonusRange() const;
  int getStartingSpellId() const;
  MonsterBonusCharacteristicsData getBonusCharacteristics() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_grade;
  int m_monsterId;
  uint m_level;
  int m_vitality;
  int m_paDodge;
  int m_pmDodge;
  int m_wisdom;
  int m_earthResistance;
  int m_airResistance;
  int m_fireResistance;
  int m_waterResistance;
  int m_neutralResistance;
  int m_gradeXp;
  int m_lifePoints;
  int m_actionPoints;
  int m_movementPoints;
  int m_damageReflect;
  uint m_hiddenLevel;
  int m_strength;
  int m_intelligence;
  int m_chance;
  int m_agility;
  int m_bonusRange;
  int m_startingSpellId;
  MonsterBonusCharacteristicsData m_bonusCharacteristics;
};

#endif // MONSTERGRADEDATA_H