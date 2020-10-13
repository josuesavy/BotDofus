#include "ArenaLeagueRewardData.h"

int ArenaLeagueRewardData::getId() const
{
  return m_id;
}

uint ArenaLeagueRewardData::getSeasonId() const
{
  return m_seasonId;
}

uint ArenaLeagueRewardData::getLeagueId() const
{
  return m_leagueId;
}

QList<uint> ArenaLeagueRewardData::getTitlesRewards() const
{
  return m_titlesRewards;
}

bool ArenaLeagueRewardData::getEndSeasonRewards() const
{
  return m_endSeasonRewards;
}

void ArenaLeagueRewardData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "seasonId")
        m_seasonId = readUInt(field->getValue());
    
    else if(field->getName() == "leagueId")
        m_leagueId = readUInt(field->getValue());
    
    else if(field->getName() == "titlesRewards")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_titlesRewards << readUInt(data);
    }
    
    else if(field->getName() == "endSeasonRewards")
        m_endSeasonRewards = readBool(field->getValue());
    
  }
}

