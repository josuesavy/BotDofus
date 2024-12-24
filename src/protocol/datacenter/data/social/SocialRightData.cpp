#include "SocialRightData.h"

int SocialRightData::getId() const
{
  return m_id;
}

uint SocialRightData::getNameId() const
{
  return m_nameId;
}

int SocialRightData::getOrder() const
{
  return m_order;
}

int SocialRightData::getGroupId() const
{
  return m_groupId;
}

void SocialRightData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
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

