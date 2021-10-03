#include "AchievementData.h"

uint AchievementData::getId() const
{
  return m_id;
}

uint AchievementData::getNameId() const
{
  return m_nameId;
}

uint AchievementData::getCategoryId() const
{
  return m_categoryId;
}

uint AchievementData::getDescriptionId() const
{
  return m_descriptionId;
}

uint AchievementData::getIconId() const
{
  return m_iconId;
}

uint AchievementData::getPoints() const
{
  return m_points;
}

uint AchievementData::getLevel() const
{
  return m_level;
}

uint AchievementData::getOrder() const
{
  return m_order;
}

bool AchievementData::getAccountLinked() const
{
  return m_accountLinked;
}

QList<int> AchievementData::getObjectiveIds() const
{
  return m_objectiveIds;
}

QList<int> AchievementData::getRewardIds() const
{
  return m_rewardIds;
}

QString AchievementData::getName() const
{
  return m_I18n->getText(m_nameId);
}

QString AchievementData::getDescription() const
{
  return m_I18n->getText(m_descriptionId);
}

void AchievementData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "categoryId")
        m_categoryId = readUInt(field->getValue());
    
    else if(field->getName() == "descriptionId")
        m_descriptionId = readUInt(field->getValue());
    
    else if(field->getName() == "iconId")
        m_iconId = readUInt(field->getValue());
    
    else if(field->getName() == "points")
        m_points = readUInt(field->getValue());
    
    else if(field->getName() == "level")
        m_level = readUInt(field->getValue());
    
    else if(field->getName() == "order")
        m_order = readUInt(field->getValue());
    
    else if(field->getName() == "accountLinked")
        m_accountLinked = readBool(field->getValue());
    
    else if(field->getName() == "objectiveIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_objectiveIds << readInt(data);
    }
    
    else if(field->getName() == "rewardIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_rewardIds << readInt(data);
    }
    
  }
}

