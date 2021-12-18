#include "GuildTagData.h"

int GuildTagData::getId() const
{
  return m_id;
}

int GuildTagData::getTypeId() const
{
  return m_typeId;
}

uint GuildTagData::getNameId() const
{
  return m_nameId;
}

int GuildTagData::getOrder() const
{
  return m_order;
}

QString GuildTagData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void GuildTagData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "typeId")
        m_typeId = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "order")
        m_order = readInt(field->getValue());
    
  }
}

