#include "AchievementProgressStepData.h"

int AchievementProgressStepData::getId() const
{
  return m_id;
}

int AchievementProgressStepData::getProgressId() const
{
  return m_progressId;
}

int AchievementProgressStepData::getScore() const
{
  return m_score;
}

bool AchievementProgressStepData::getIsCosmetic() const
{
  return m_isCosmetic;
}

int AchievementProgressStepData::getAchievementId() const
{
  return m_achievementId;
}

bool AchievementProgressStepData::getIsBuyable() const
{
  return m_isBuyable;
}

void AchievementProgressStepData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "progressId")
        m_progressId = readInt(field->getValue());
    
    else if(field->getName() == "score")
        m_score = readInt(field->getValue());
    
    else if(field->getName() == "isCosmetic")
        m_isCosmetic = readBool(field->getValue());
    
    else if(field->getName() == "achievementId")
        m_achievementId = readInt(field->getValue());
    
    else if(field->getName() == "isBuyable")
        m_isBuyable = readBool(field->getValue());
    
  }
}

