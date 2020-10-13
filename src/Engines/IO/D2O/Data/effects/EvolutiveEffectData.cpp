#include "EvolutiveEffectData.h"

int EvolutiveEffectData::getId() const
{
  return m_id;
}

int EvolutiveEffectData::getActionId() const
{
  return m_actionId;
}

int EvolutiveEffectData::getTargetId() const
{
  return m_targetId;
}

QList<QList<double>> EvolutiveEffectData::getProgressionPerLevelRange() const
{
  return m_progressionPerLevelRange;
}

void EvolutiveEffectData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "actionId")
        m_actionId = readInt(field->getValue());
    
    else if(field->getName() == "targetId")
        m_targetId = readInt(field->getValue());
    
    else if(field->getName() == "progressionPerLevelRange")
    {
      foreach(const QByteArray &firstList, readVector(field->getValue()))
      {
        QList<double> secondList;
        
        foreach (const QByteArray &data, readVector(firstList))
            secondList << readDouble(data);
        
        m_progressionPerLevelRange << secondList;
      }
    }
    
  }
}

