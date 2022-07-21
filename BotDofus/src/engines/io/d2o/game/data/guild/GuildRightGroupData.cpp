#include "GuildRightGroupData.h"

int GuildRightGroupData::getId() const
{
  return m_id;
}

uint GuildRightGroupData::getNameId() const
{
  return m_nameId;
}

int GuildRightGroupData::getOrder() const
{
  return m_order;
}

QList<GuildRightData> GuildRightGroupData::getGuildRights() const
{
  return m_guildRights;
}

QString GuildRightGroupData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void GuildRightGroupData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
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
    
    else if(field->getName() == "guildRights")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_guildRights << *qSharedPointerCast<GuildRightData>(readObject(data, field)).data();
    }
    
  }
}

