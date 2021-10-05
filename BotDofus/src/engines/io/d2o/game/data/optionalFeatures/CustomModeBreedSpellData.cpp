#include "CustomModeBreedSpellData.h"

int CustomModeBreedSpellData::getId() const
{
  return m_id;
}

int CustomModeBreedSpellData::getPairId() const
{
  return m_pairId;
}

int CustomModeBreedSpellData::getBreedId() const
{
  return m_breedId;
}

bool CustomModeBreedSpellData::getIsInitialSpell() const
{
  return m_isInitialSpell;
}

bool CustomModeBreedSpellData::getIsHidden() const
{
  return m_isHidden;
}

void CustomModeBreedSpellData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "pairId")
        m_pairId = readInt(field->getValue());
    
    else if(field->getName() == "breedId")
        m_breedId = readInt(field->getValue());
    
    else if(field->getName() == "isInitialSpell")
        m_isInitialSpell = readBool(field->getValue());
    
    else if(field->getName() == "isHidden")
        m_isHidden = readBool(field->getValue());
    
  }
}

