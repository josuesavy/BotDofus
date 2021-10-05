#include "EffectInstanceLadderData.h"

uint EffectInstanceLadderData::getMonsterCount() const
{
  return m_monsterCount;
}

void EffectInstanceLadderData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  EffectInstanceCreatureData::loadData(fields, I18n);
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "monsterCount")
        m_monsterCount = readUInt(field->getValue());
    
  }
}

