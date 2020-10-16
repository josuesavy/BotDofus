#include "JobData.h"

int JobData::getId() const
{
  return m_id;
}

uint JobData::getNameId() const
{
  return m_nameId;
}

int JobData::getIconId() const
{
  return m_iconId;
}

bool JobData::getHasLegendaryCraft() const
{
  return m_hasLegendaryCraft;
}

QString JobData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void JobData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "iconId")
        m_iconId = readInt(field->getValue());
    
    else if(field->getName() == "hasLegendaryCraft")
        m_hasLegendaryCraft = readBool(field->getValue());
    
  }
}

