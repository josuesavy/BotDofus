#include "RandomDropItemData.h"

uint RandomDropItemData::getId() const
{
  return m_id;
}

uint RandomDropItemData::getItemId() const
{
  return m_itemId;
}

double RandomDropItemData::getProbability() const
{
  return m_probability;
}

uint RandomDropItemData::getMinQuantity() const
{
  return m_minQuantity;
}

uint RandomDropItemData::getMaxQuantity() const
{
  return m_maxQuantity;
}

void RandomDropItemData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "itemId")
        m_itemId = readUInt(field->getValue());
    
    else if(field->getName() == "probability")
        m_probability = readDouble(field->getValue());
    
    else if(field->getName() == "minQuantity")
        m_minQuantity = readUInt(field->getValue());
    
    else if(field->getName() == "maxQuantity")
        m_maxQuantity = readUInt(field->getValue());
    
  }
}

