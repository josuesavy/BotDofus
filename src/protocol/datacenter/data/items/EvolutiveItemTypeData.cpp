#include "EvolutiveItemTypeData.h"

int EvolutiveItemTypeData::getId() const
{
  return m_id;
}

uint EvolutiveItemTypeData::getMaxLevel() const
{
  return m_maxLevel;
}

double EvolutiveItemTypeData::getExperienceBoost() const
{
  return m_experienceBoost;
}

QList<int> EvolutiveItemTypeData::getExperienceByLevel() const
{
  return m_experienceByLevel;
}

void EvolutiveItemTypeData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "maxLevel")
        m_maxLevel = readUInt(field->getValue());
    
    else if(field->getName() == "experienceBoost")
        m_experienceBoost = readDouble(field->getValue());
    
    else if(field->getName() == "experienceByLevel")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_experienceByLevel << readInt(data);
    }
    
  }
}

