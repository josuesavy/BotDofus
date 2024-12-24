#include "ServerLangData.h"

int ServerLangData::getId() const
{
  return m_id;
}

uint ServerLangData::getNameId() const
{
  return m_nameId;
}

QString ServerLangData::getLangCode() const
{
  return m_langCode;
}

QString ServerLangData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void ServerLangData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "langCode")
        m_langCode = readUTF(field->getValue());
    
  }
}

