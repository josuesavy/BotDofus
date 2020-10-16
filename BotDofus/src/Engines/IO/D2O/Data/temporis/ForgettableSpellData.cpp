#include "ForgettableSpellData.h"

int ForgettableSpellData::getId() const
{
  return m_id;
}

int ForgettableSpellData::getPairId() const
{
  return m_pairId;
}

int ForgettableSpellData::getItemId() const
{
  return m_itemId;
}

void ForgettableSpellData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "pairId")
        m_pairId = readInt(field->getValue());
    
    else if(field->getName() == "itemId")
        m_itemId = readInt(field->getValue());
    
  }
}

