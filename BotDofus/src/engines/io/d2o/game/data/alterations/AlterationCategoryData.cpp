#include "AlterationCategoryData.h"

uint AlterationCategoryData::getId() const
{
  return m_id;
}

uint AlterationCategoryData::getNameId() const
{
  return m_nameId;
}

uint AlterationCategoryData::getParentId() const
{
  return m_parentId;
}

QString AlterationCategoryData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void AlterationCategoryData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "parentId")
        m_parentId = readUInt(field->getValue());
    
  }
}

