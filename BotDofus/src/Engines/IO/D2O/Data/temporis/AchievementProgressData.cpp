#include "AchievementProgressData.h"

int AchievementProgressData::getId() const
{
  return m_id;
}

QString AchievementProgressData::getName() const
{
  return m_name;
}

int AchievementProgressData::getSeasonId() const
{
  return m_seasonId;
}

void AchievementProgressData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "name")
        m_name = readUTF(field->getValue());
    
    else if(field->getName() == "seasonId")
        m_seasonId = readInt(field->getValue());
    
  }
}

