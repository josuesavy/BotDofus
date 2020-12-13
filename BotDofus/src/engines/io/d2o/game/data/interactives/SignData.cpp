#include "SignData.h"

int SignData::getId() const
{
  return m_id;
}

QString SignData::getParams() const
{
  return m_params;
}

int SignData::getSkillId() const
{
  return m_skillId;
}

uint SignData::getTextKey() const
{
  return m_textKey;
}

void SignData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "params")
        m_params = readUTF(field->getValue());
    
    else if(field->getName() == "skillId")
        m_skillId = readInt(field->getValue());
    
    else if(field->getName() == "textKey")
        m_textKey = readUInt(field->getValue());
    
  }
}

