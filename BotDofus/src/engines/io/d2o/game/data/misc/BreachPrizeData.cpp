#include "BreachPrizeData.h"

int BreachPrizeData::getId() const
{
  return m_id;
}

uint BreachPrizeData::getNameId() const
{
  return m_nameId;
}

int BreachPrizeData::getCurrency() const
{
  return m_currency;
}

QString BreachPrizeData::getTooltipKey() const
{
  return m_tooltipKey;
}

uint BreachPrizeData::getDescriptionKey() const
{
  return m_descriptionKey;
}

int BreachPrizeData::getCategoryId() const
{
  return m_categoryId;
}

int BreachPrizeData::getItemId() const
{
  return m_itemId;
}

QString BreachPrizeData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void BreachPrizeData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "currency")
        m_currency = readInt(field->getValue());
    
    else if(field->getName() == "tooltipKey")
        m_tooltipKey = readUTF(field->getValue());
    
    else if(field->getName() == "descriptionKey")
        m_descriptionKey = readUInt(field->getValue());
    
    else if(field->getName() == "categoryId")
        m_categoryId = readInt(field->getValue());
    
    else if(field->getName() == "itemId")
        m_itemId = readInt(field->getValue());
    
  }
}

