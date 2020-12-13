#include "MonsterRaceData.h"

int MonsterRaceData::getId() const
{
  return m_id;
}

int MonsterRaceData::getSuperRaceId() const
{
  return m_superRaceId;
}

uint MonsterRaceData::getNameId() const
{
  return m_nameId;
}

QList<uint> MonsterRaceData::getMonsters() const
{
  return m_monsters;
}

int MonsterRaceData::getAggressiveZoneSize() const
{
  return m_aggressiveZoneSize;
}

int MonsterRaceData::getAggressiveLevelDiff() const
{
  return m_aggressiveLevelDiff;
}

QString MonsterRaceData::getAggressiveImmunityCriterion() const
{
  return m_aggressiveImmunityCriterion;
}

int MonsterRaceData::getAggressiveAttackDelay() const
{
  return m_aggressiveAttackDelay;
}

QString MonsterRaceData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void MonsterRaceData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "superRaceId")
        m_superRaceId = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "monsters")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_monsters << readUInt(data);
    }
    
    else if(field->getName() == "aggressiveZoneSize")
        m_aggressiveZoneSize = readInt(field->getValue());
    
    else if(field->getName() == "aggressiveLevelDiff")
        m_aggressiveLevelDiff = readInt(field->getValue());
    
    else if(field->getName() == "aggressiveImmunityCriterion")
        m_aggressiveImmunityCriterion = readUTF(field->getValue());
    
    else if(field->getName() == "aggressiveAttackDelay")
        m_aggressiveAttackDelay = readInt(field->getValue());
    
  }
}

