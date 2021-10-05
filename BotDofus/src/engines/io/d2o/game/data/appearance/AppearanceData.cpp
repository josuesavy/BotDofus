#include "AppearanceData.h"

uint AppearanceData::getId() const
{
  return m_id;
}

uint AppearanceData::getType() const
{
  return m_type;
}

QString AppearanceData::getData() const
{
  return m_data;
}

void AppearanceData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "type")
        m_type = readUInt(field->getValue());
    
    else if(field->getName() == "data")
        m_data = readUTF(field->getValue());
    
  }
}

