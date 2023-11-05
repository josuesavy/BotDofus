#include "CreatureBoneTypeData.h"

int CreatureBoneTypeData::getId() const
{
  return m_id;
}

int CreatureBoneTypeData::getCreatureBoneId() const
{
  return m_creatureBoneId;
}

void CreatureBoneTypeData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "creatureBoneId")
        m_creatureBoneId = readInt(field->getValue());
    
  }
}

