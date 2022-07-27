#include "GuildRightData.h"

int GuildRightData::getId() const
{
  return m_id;
}

uint GuildRightData::getNameId() const
{
  return m_nameId;
}

int GuildRightData::getOrder() const
{
  return m_order;
}

int GuildRightData::getGroupId() const
{
  return m_groupId;
}

QString GuildRightData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void GuildRightData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "order")
        m_order = readInt(field->getValue());
    
    else if(field->getName() == "groupId")
        m_groupId = readInt(field->getValue());
    
  }
}

