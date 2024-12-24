#include "AchievementRewardData.h"

uint AchievementRewardData::getId() const
{
  return m_id;
}

uint AchievementRewardData::getAchievementId() const
{
  return m_achievementId;
}

QString AchievementRewardData::getCriteria() const
{
  return m_criteria;
}

double AchievementRewardData::getKamasRatio() const
{
  return m_kamasRatio;
}

double AchievementRewardData::getExperienceRatio() const
{
  return m_experienceRatio;
}

bool AchievementRewardData::getKamasScaleWithPlayerLevel() const
{
  return m_kamasScaleWithPlayerLevel;
}

QList<uint> AchievementRewardData::getItemsReward() const
{
  return m_itemsReward;
}

QList<uint> AchievementRewardData::getItemsQuantityReward() const
{
  return m_itemsQuantityReward;
}

QList<uint> AchievementRewardData::getEmotesReward() const
{
  return m_emotesReward;
}

QList<uint> AchievementRewardData::getSpellsReward() const
{
  return m_spellsReward;
}

QList<uint> AchievementRewardData::getTitlesReward() const
{
  return m_titlesReward;
}

QList<uint> AchievementRewardData::getOrnamentsReward() const
{
  return m_ornamentsReward;
}

uint AchievementRewardData::getGuildPoints() const
{
  return m_guildPoints;
}

void AchievementRewardData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "achievementId")
        m_achievementId = readUInt(field->getValue());
    
    else if(field->getName() == "criteria")
        m_criteria = readUTF(field->getValue());
    
    else if(field->getName() == "kamasRatio")
        m_kamasRatio = readDouble(field->getValue());
    
    else if(field->getName() == "experienceRatio")
        m_experienceRatio = readDouble(field->getValue());
    
    else if(field->getName() == "kamasScaleWithPlayerLevel")
        m_kamasScaleWithPlayerLevel = readBool(field->getValue());
    
    else if(field->getName() == "itemsReward")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_itemsReward << readUInt(data);
    }
    
    else if(field->getName() == "itemsQuantityReward")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_itemsQuantityReward << readUInt(data);
    }
    
    else if(field->getName() == "emotesReward")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_emotesReward << readUInt(data);
    }
    
    else if(field->getName() == "spellsReward")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_spellsReward << readUInt(data);
    }
    
    else if(field->getName() == "titlesReward")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_titlesReward << readUInt(data);
    }
    
    else if(field->getName() == "ornamentsReward")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_ornamentsReward << readUInt(data);
    }
    
    else if(field->getName() == "guildPoints")
        m_guildPoints = readUInt(field->getValue());
    
  }
}

