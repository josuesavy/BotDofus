#include "MonsterDropCoefficientData.h"

uint MonsterDropCoefficientData::getMonsterId() const
{
  return m_monsterId;
}

uint MonsterDropCoefficientData::getMonsterGrade() const
{
  return m_monsterGrade;
}

double MonsterDropCoefficientData::getDropCoefficient() const
{
  return m_dropCoefficient;
}

QString MonsterDropCoefficientData::getCriteria() const
{
  return m_criteria;
}

void MonsterDropCoefficientData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "monsterId")
        m_monsterId = readUInt(field->getValue());
    
    else if(field->getName() == "monsterGrade")
        m_monsterGrade = readUInt(field->getValue());
    
    else if(field->getName() == "dropCoefficient")
        m_dropCoefficient = readDouble(field->getValue());
    
    else if(field->getName() == "criteria")
        m_criteria = readUTF(field->getValue());
    
  }
}

