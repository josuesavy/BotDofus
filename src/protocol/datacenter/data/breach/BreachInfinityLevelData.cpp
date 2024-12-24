#include "BreachInfinityLevelData.h"

uint BreachInfinityLevelData::getId() const
{
  return m_id;
}

uint BreachInfinityLevelData::getNameId() const
{
  return m_nameId;
}

uint BreachInfinityLevelData::getLevel() const
{
  return m_level;
}

QString BreachInfinityLevelData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void BreachInfinityLevelData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "level")
        m_level = readUInt(field->getValue());
    
  }
}

