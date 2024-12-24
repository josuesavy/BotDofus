#include "CollectableData.h"

int CollectableData::getEntityId() const
{
  return m_entityId;
}

int CollectableData::getName() const
{
  return m_name;
}

int CollectableData::getTypeId() const
{
  return m_typeId;
}

int CollectableData::getGfxId() const
{
  return m_gfxId;
}

int CollectableData::getOrder() const
{
  return m_order;
}

int CollectableData::getRarity() const
{
  return m_rarity;
}

void CollectableData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "entityId")
        m_entityId = readInt(field->getValue());
    
    else if(field->getName() == "name")
        m_name = readInt(field->getValue());
    
    else if(field->getName() == "typeId")
        m_typeId = readInt(field->getValue());
    
    else if(field->getName() == "gfxId")
        m_gfxId = readInt(field->getValue());
    
    else if(field->getName() == "order")
        m_order = readInt(field->getValue());
    
    else if(field->getName() == "rarity")
        m_rarity = readInt(field->getValue());
    
  }
}

