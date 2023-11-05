#include "SocialRightGroupData.h"

int SocialRightGroupData::getId() const
{
  return m_id;
}

uint SocialRightGroupData::getNameId() const
{
  return m_nameId;
}

int SocialRightGroupData::getOrder() const
{
  return m_order;
}

void SocialRightGroupData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
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
    
  }
}

