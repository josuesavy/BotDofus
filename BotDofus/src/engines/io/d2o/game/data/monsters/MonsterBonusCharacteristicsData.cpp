#include "MonsterBonusCharacteristicsData.h"

int MonsterBonusCharacteristicsData::getLifePoints() const
{
  return m_lifePoints;
}

int MonsterBonusCharacteristicsData::getStrength() const
{
  return m_strength;
}

int MonsterBonusCharacteristicsData::getWisdom() const
{
  return m_wisdom;
}

int MonsterBonusCharacteristicsData::getChance() const
{
  return m_chance;
}

int MonsterBonusCharacteristicsData::getAgility() const
{
  return m_agility;
}

int MonsterBonusCharacteristicsData::getIntelligence() const
{
  return m_intelligence;
}

int MonsterBonusCharacteristicsData::getEarthResistance() const
{
  return m_earthResistance;
}

int MonsterBonusCharacteristicsData::getFireResistance() const
{
  return m_fireResistance;
}

int MonsterBonusCharacteristicsData::getWaterResistance() const
{
  return m_waterResistance;
}

int MonsterBonusCharacteristicsData::getAirResistance() const
{
  return m_airResistance;
}

int MonsterBonusCharacteristicsData::getNeutralResistance() const
{
  return m_neutralResistance;
}

int MonsterBonusCharacteristicsData::getTackleEvade() const
{
  return m_tackleEvade;
}

int MonsterBonusCharacteristicsData::getTackleBlock() const
{
  return m_tackleBlock;
}

int MonsterBonusCharacteristicsData::getBonusEarthDamage() const
{
  return m_bonusEarthDamage;
}

int MonsterBonusCharacteristicsData::getBonusFireDamage() const
{
  return m_bonusFireDamage;
}

int MonsterBonusCharacteristicsData::getBonusWaterDamage() const
{
  return m_bonusWaterDamage;
}

int MonsterBonusCharacteristicsData::getBonusAirDamage() const
{
  return m_bonusAirDamage;
}

int MonsterBonusCharacteristicsData::getAPRemoval() const
{
  return m_APRemoval;
}

void MonsterBonusCharacteristicsData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "lifePoints")
        m_lifePoints = readInt(field->getValue());
    
    else if(field->getName() == "strength")
        m_strength = readInt(field->getValue());
    
    else if(field->getName() == "wisdom")
        m_wisdom = readInt(field->getValue());
    
    else if(field->getName() == "chance")
        m_chance = readInt(field->getValue());
    
    else if(field->getName() == "agility")
        m_agility = readInt(field->getValue());
    
    else if(field->getName() == "intelligence")
        m_intelligence = readInt(field->getValue());
    
    else if(field->getName() == "earthResistance")
        m_earthResistance = readInt(field->getValue());
    
    else if(field->getName() == "fireResistance")
        m_fireResistance = readInt(field->getValue());
    
    else if(field->getName() == "waterResistance")
        m_waterResistance = readInt(field->getValue());
    
    else if(field->getName() == "airResistance")
        m_airResistance = readInt(field->getValue());
    
    else if(field->getName() == "neutralResistance")
        m_neutralResistance = readInt(field->getValue());
    
    else if(field->getName() == "tackleEvade")
        m_tackleEvade = readInt(field->getValue());
    
    else if(field->getName() == "tackleBlock")
        m_tackleBlock = readInt(field->getValue());
    
    else if(field->getName() == "bonusEarthDamage")
        m_bonusEarthDamage = readInt(field->getValue());
    
    else if(field->getName() == "bonusFireDamage")
        m_bonusFireDamage = readInt(field->getValue());
    
    else if(field->getName() == "bonusWaterDamage")
        m_bonusWaterDamage = readInt(field->getValue());
    
    else if(field->getName() == "bonusAirDamage")
        m_bonusAirDamage = readInt(field->getValue());
    
    else if(field->getName() == "APRemoval")
        m_APRemoval = readInt(field->getValue());
    
  }
}

