#include "AlterationData.h"

uint AlterationData::getId() const
{
  return m_id;
}

uint AlterationData::getNameId() const
{
  return m_nameId;
}

uint AlterationData::getDescriptionId() const
{
  return m_descriptionId;
}

uint AlterationData::getCategoryId() const
{
  return m_categoryId;
}

uint AlterationData::getIconId() const
{
  return m_iconId;
}

bool AlterationData::getIsVisible() const
{
  return m_isVisible;
}

QString AlterationData::getCriteria() const
{
  return m_criteria;
}

bool AlterationData::getIsWebDisplay() const
{
  return m_isWebDisplay;
}

QList<EffectInstanceData> AlterationData::getPossibleEffects() const
{
  return m_possibleEffects;
}

QString AlterationData::getName() const
{
  return m_I18n->getText(m_nameId);
}

QString AlterationData::getDescription() const
{
  return m_I18n->getText(m_descriptionId);
}

QString AlterationData::getCategory() const
{
  return m_I18n->getText(m_categoryId);
}

void AlterationData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "descriptionId")
        m_descriptionId = readUInt(field->getValue());
    
    else if(field->getName() == "categoryId")
        m_categoryId = readUInt(field->getValue());
    
    else if(field->getName() == "iconId")
        m_iconId = readUInt(field->getValue());
    
    else if(field->getName() == "isVisible")
        m_isVisible = readBool(field->getValue());
    
    else if(field->getName() == "criteria")
        m_criteria = readUTF(field->getValue());
    
    else if(field->getName() == "isWebDisplay")
        m_isWebDisplay = readBool(field->getValue());
    
    else if(field->getName() == "possibleEffects")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_possibleEffects << *qSharedPointerCast<EffectInstanceData>(readObject(data, field)).data();
    }
    
  }
}

