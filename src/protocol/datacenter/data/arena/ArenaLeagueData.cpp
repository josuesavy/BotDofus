#include "ArenaLeagueData.h"

int ArenaLeagueData::getId() const
{
  return m_id;
}

uint ArenaLeagueData::getNameId() const
{
  return m_nameId;
}

uint ArenaLeagueData::getOrnamentId() const
{
  return m_ornamentId;
}

QString ArenaLeagueData::getIcon() const
{
  return m_icon;
}

QString ArenaLeagueData::getIllus() const
{
  return m_illus;
}

bool ArenaLeagueData::getIsLastLeague() const
{
  return m_isLastLeague;
}

int ArenaLeagueData::getLowRatingBound() const
{
  return m_lowRatingBound;
}

int ArenaLeagueData::getHighRatingBound() const
{
  return m_highRatingBound;
}

QString ArenaLeagueData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void ArenaLeagueData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "ornamentId")
        m_ornamentId = readUInt(field->getValue());
    
    else if(field->getName() == "icon")
        m_icon = readUTF(field->getValue());
    
    else if(field->getName() == "illus")
        m_illus = readUTF(field->getValue());
    
    else if(field->getName() == "isLastLeague")
        m_isLastLeague = readBool(field->getValue());
    
    else if(field->getName() == "lowRatingBound")
        m_lowRatingBound = readInt(field->getValue());
    
    else if(field->getName() == "highRatingBound")
        m_highRatingBound = readInt(field->getValue());
    
  }
}

