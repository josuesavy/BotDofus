#include "SpellScriptData.h"

int SpellScriptData::getId() const
{
  return m_id;
}

int SpellScriptData::getTypeId() const
{
  return m_typeId;
}

QString SpellScriptData::getRawParams() const
{
  return m_rawParams;
}

void SpellScriptData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "typeId")
        m_typeId = readInt(field->getValue());
    
    else if(field->getName() == "rawParams")
        m_rawParams = readUTF(field->getValue());
    
  }
}

