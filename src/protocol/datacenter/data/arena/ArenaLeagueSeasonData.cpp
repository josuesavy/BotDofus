#include "ArenaLeagueSeasonData.h"

int ArenaLeagueSeasonData::getId() const
{
  return m_id;
}

uint ArenaLeagueSeasonData::getNameId() const
{
  return m_nameId;
}

QString ArenaLeagueSeasonData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void ArenaLeagueSeasonData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
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

