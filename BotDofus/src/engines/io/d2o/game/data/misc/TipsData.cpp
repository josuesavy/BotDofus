#include "TipsData.h"

int TipsData::getId() const
{
  return m_id;
}

uint TipsData::getDescId() const
{
  return m_descId;
}

void TipsData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "descId")
        m_descId = readUInt(field->getValue());
    
  }
}

