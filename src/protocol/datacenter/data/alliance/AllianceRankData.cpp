#include "AllianceRankData.h"

int AllianceRankData::getId() const
{
  return m_id;
}

uint AllianceRankData::getNameId() const
{
  return m_nameId;
}

int AllianceRankData::getOrder() const
{
  return m_order;
}

bool AllianceRankData::getIsModifiable() const
{
  return m_isModifiable;
}

uint AllianceRankData::getGfxId() const
{
  return m_gfxId;
}

QString AllianceRankData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void AllianceRankData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
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
    
    else if(field->getName() == "isModifiable")
        m_isModifiable = readBool(field->getValue());
    
    else if(field->getName() == "gfxId")
        m_gfxId = readUInt(field->getValue());
    
  }
}

