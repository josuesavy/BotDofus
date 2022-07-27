#include "EffectInstanceDiceData.h"

uint EffectInstanceDiceData::getDiceNum() const
{
  return m_diceNum;
}

uint EffectInstanceDiceData::getDiceSide() const
{
  return m_diceSide;
}

void EffectInstanceDiceData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  EffectInstanceIntegerData::loadData(fields, I18n);
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "diceNum")
        m_diceNum = readUInt(field->getValue());
    
    else if(field->getName() == "diceSide")
        m_diceSide = readUInt(field->getValue());
    
  }
}

