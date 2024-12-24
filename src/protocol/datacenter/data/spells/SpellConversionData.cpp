#include "SpellConversionData.h"

uint SpellConversionData::getOldSpellId() const
{
  return m_oldSpellId;
}

uint SpellConversionData::getNewSpellId() const
{
  return m_newSpellId;
}

void SpellConversionData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "oldSpellId")
        m_oldSpellId = readUInt(field->getValue());
    
    else if(field->getName() == "newSpellId")
        m_newSpellId = readUInt(field->getValue());
    
  }
}

