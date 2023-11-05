#include "NamingRuleData.h"

uint NamingRuleData::getId() const
{
  return m_id;
}

uint NamingRuleData::getMinLength() const
{
  return m_minLength;
}

uint NamingRuleData::getMaxLength() const
{
  return m_maxLength;
}

QString NamingRuleData::getRegexp() const
{
  return m_regexp;
}

void NamingRuleData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "minLength")
        m_minLength = readUInt(field->getValue());
    
    else if(field->getName() == "maxLength")
        m_maxLength = readUInt(field->getValue());
    
    else if(field->getName() == "regexp")
        m_regexp = readUTF(field->getValue());
    
  }
}

