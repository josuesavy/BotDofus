#include "CharacterXPMappingData.h"

int CharacterXPMappingData::getLevel() const
{
  return m_level;
}

double CharacterXPMappingData::getExperiencePoints() const
{
  return m_experiencePoints;
}

void CharacterXPMappingData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "level")
        m_level = readInt(field->getValue());
    
    else if(field->getName() == "experiencePoints")
        m_experiencePoints = readDouble(field->getValue());
    
  }
}

