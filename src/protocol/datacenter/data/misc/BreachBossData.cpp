#include "BreachBossData.h"

int BreachBossData::getId() const
{
  return m_id;
}

int BreachBossData::getMonsterId() const
{
  return m_monsterId;
}

int BreachBossData::getCategory() const
{
  return m_category;
}

QString BreachBossData::getApparitionCriterion() const
{
  return m_apparitionCriterion;
}

QString BreachBossData::getAccessCriterion() const
{
  return m_accessCriterion;
}

QList<int> BreachBossData::getIncompatibleBosses() const
{
  return m_incompatibleBosses;
}

uint BreachBossData::getRewardId() const
{
  return m_rewardId;
}

void BreachBossData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "monsterId")
        m_monsterId = readInt(field->getValue());
    
    else if(field->getName() == "category")
        m_category = readInt(field->getValue());
    
    else if(field->getName() == "apparitionCriterion")
        m_apparitionCriterion = readUTF(field->getValue());
    
    else if(field->getName() == "accessCriterion")
        m_accessCriterion = readUTF(field->getValue());
    
    else if(field->getName() == "incompatibleBosses")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_incompatibleBosses << readInt(data);
    }
    
    else if(field->getName() == "rewardId")
        m_rewardId = readUInt(field->getValue());
    
  }
}

