#include "SocialTagsTypeData.h"

int SocialTagsTypeData::getId() const
{
  return m_id;
}

uint SocialTagsTypeData::getNameId() const
{
  return m_nameId;
}

QString SocialTagsTypeData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void SocialTagsTypeData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
  }
}

