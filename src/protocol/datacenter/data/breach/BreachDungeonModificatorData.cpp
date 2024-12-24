#include "BreachDungeonModificatorData.h"

uint BreachDungeonModificatorData::getId() const
{
  return m_id;
}

uint BreachDungeonModificatorData::getModificatorId() const
{
  return m_modificatorId;
}

QString BreachDungeonModificatorData::getCriterion() const
{
  return m_criterion;
}

double BreachDungeonModificatorData::getAdditionalRewardPercent() const
{
  return m_additionalRewardPercent;
}

double BreachDungeonModificatorData::getScore() const
{
  return m_score;
}

bool BreachDungeonModificatorData::getIsPositiveForPlayers() const
{
  return m_isPositiveForPlayers;
}

QString BreachDungeonModificatorData::getTooltipBaseline() const
{
  return m_tooltipBaseline;
}

void BreachDungeonModificatorData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "modificatorId")
        m_modificatorId = readUInt(field->getValue());
    
    else if(field->getName() == "criterion")
        m_criterion = readUTF(field->getValue());
    
    else if(field->getName() == "additionalRewardPercent")
        m_additionalRewardPercent = readDouble(field->getValue());
    
    else if(field->getName() == "score")
        m_score = readDouble(field->getValue());
    
    else if(field->getName() == "isPositiveForPlayers")
        m_isPositiveForPlayers = readBool(field->getValue());
    
    else if(field->getName() == "tooltipBaseline")
        m_tooltipBaseline = readUTF(field->getValue());
    
  }
}

