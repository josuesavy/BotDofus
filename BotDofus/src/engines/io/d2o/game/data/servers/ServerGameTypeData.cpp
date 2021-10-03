#include "ServerGameTypeData.h"

int ServerGameTypeData::getId() const
{
  return m_id;
}

bool ServerGameTypeData::getSelectableByPlayer() const
{
  return m_selectableByPlayer;
}

uint ServerGameTypeData::getNameId() const
{
  return m_nameId;
}

uint ServerGameTypeData::getRulesId() const
{
  return m_rulesId;
}

uint ServerGameTypeData::getDescriptionId() const
{
  return m_descriptionId;
}

QString ServerGameTypeData::getName() const
{
  return m_I18n->getText(m_nameId);
}

QString ServerGameTypeData::getRules() const
{
  return m_I18n->getText(m_rulesId);
}

QString ServerGameTypeData::getDescription() const
{
  return m_I18n->getText(m_descriptionId);
}

void ServerGameTypeData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "selectableByPlayer")
        m_selectableByPlayer = readBool(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "rulesId")
        m_rulesId = readUInt(field->getValue());
    
    else if(field->getName() == "descriptionId")
        m_descriptionId = readUInt(field->getValue());
    
  }
}

