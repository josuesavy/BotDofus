#include "ItemTypeData.h"

int ItemTypeData::getId() const
{
  return m_id;
}

uint ItemTypeData::getNameId() const
{
  return m_nameId;
}

uint ItemTypeData::getSuperTypeId() const
{
  return m_superTypeId;
}

uint ItemTypeData::getCategoryId() const
{
  return m_categoryId;
}

bool ItemTypeData::getIsInEncyclopedia() const
{
  return m_isInEncyclopedia;
}

bool ItemTypeData::getPlural() const
{
  return m_plural;
}

uint ItemTypeData::getGender() const
{
  return m_gender;
}

QString ItemTypeData::getRawZone() const
{
  return m_rawZone;
}

bool ItemTypeData::getMimickable() const
{
  return m_mimickable;
}

int ItemTypeData::getCraftXpRatio() const
{
  return m_craftXpRatio;
}

int ItemTypeData::getEvolutiveTypeId() const
{
  return m_evolutiveTypeId;
}

QString ItemTypeData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void ItemTypeData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "superTypeId")
        m_superTypeId = readUInt(field->getValue());
    
    else if(field->getName() == "categoryId")
        m_categoryId = readUInt(field->getValue());
    
    else if(field->getName() == "isInEncyclopedia")
        m_isInEncyclopedia = readBool(field->getValue());
    
    else if(field->getName() == "plural")
        m_plural = readBool(field->getValue());
    
    else if(field->getName() == "gender")
        m_gender = readUInt(field->getValue());
    
    else if(field->getName() == "rawZone")
        m_rawZone = readUTF(field->getValue());
    
    else if(field->getName() == "mimickable")
        m_mimickable = readBool(field->getValue());
    
    else if(field->getName() == "craftXpRatio")
        m_craftXpRatio = readInt(field->getValue());
    
    else if(field->getName() == "evolutiveTypeId")
        m_evolutiveTypeId = readInt(field->getValue());
    
  }
}

