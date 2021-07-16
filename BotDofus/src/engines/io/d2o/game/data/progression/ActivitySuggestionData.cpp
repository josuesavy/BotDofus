#include "ActivitySuggestionData.h"

int ActivitySuggestionData::getId() const
{
  return m_id;
}

uint ActivitySuggestionData::getNameId() const
{
  return m_nameId;
}

uint ActivitySuggestionData::getDescriptionId() const
{
  return m_descriptionId;
}

int ActivitySuggestionData::getCategoryId() const
{
  return m_categoryId;
}

uint ActivitySuggestionData::getLevel() const
{
  return m_level;
}

double ActivitySuggestionData::getMapId() const
{
  return m_mapId;
}

bool ActivitySuggestionData::getIsLarge() const
{
  return m_isLarge;
}

double ActivitySuggestionData::getStartDate() const
{
  return m_startDate;
}

double ActivitySuggestionData::getEndDate() const
{
  return m_endDate;
}

QString ActivitySuggestionData::getIcon() const
{
  return m_icon;
}

QString ActivitySuggestionData::getName() const
{
  return m_I18n->getText(m_nameId);
}

QString ActivitySuggestionData::getDescription() const
{
  return m_I18n->getText(m_descriptionId);
}

void ActivitySuggestionData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "descriptionId")
        m_descriptionId = readUInt(field->getValue());
    
    else if(field->getName() == "categoryId")
        m_categoryId = readInt(field->getValue());
    
    else if(field->getName() == "level")
        m_level = readUInt(field->getValue());
    
    else if(field->getName() == "mapId")
        m_mapId = readDouble(field->getValue());
    
    else if(field->getName() == "isLarge")
        m_isLarge = readBool(field->getValue());
    
    else if(field->getName() == "startDate")
        m_startDate = readDouble(field->getValue());
    
    else if(field->getName() == "endDate")
        m_endDate = readDouble(field->getValue());
    
    else if(field->getName() == "icon")
        m_icon = readUTF(field->getValue());
    
  }
}

