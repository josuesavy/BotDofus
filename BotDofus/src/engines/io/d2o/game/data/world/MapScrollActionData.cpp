#include "MapScrollActionData.h"

double MapScrollActionData::getId() const
{
  return m_id;
}

bool MapScrollActionData::getRightExists() const
{
  return m_rightExists;
}

bool MapScrollActionData::getBottomExists() const
{
  return m_bottomExists;
}

bool MapScrollActionData::getLeftExists() const
{
  return m_leftExists;
}

bool MapScrollActionData::getTopExists() const
{
  return m_topExists;
}

double MapScrollActionData::getRightMapId() const
{
  return m_rightMapId;
}

double MapScrollActionData::getBottomMapId() const
{
  return m_bottomMapId;
}

double MapScrollActionData::getLeftMapId() const
{
  return m_leftMapId;
}

double MapScrollActionData::getTopMapId() const
{
  return m_topMapId;
}

void MapScrollActionData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readDouble(field->getValue());
    
    else if(field->getName() == "rightExists")
        m_rightExists = readBool(field->getValue());
    
    else if(field->getName() == "bottomExists")
        m_bottomExists = readBool(field->getValue());
    
    else if(field->getName() == "leftExists")
        m_leftExists = readBool(field->getValue());
    
    else if(field->getName() == "topExists")
        m_topExists = readBool(field->getValue());
    
    else if(field->getName() == "rightMapId")
        m_rightMapId = readDouble(field->getValue());
    
    else if(field->getName() == "bottomMapId")
        m_bottomMapId = readDouble(field->getValue());
    
    else if(field->getName() == "leftMapId")
        m_leftMapId = readDouble(field->getValue());
    
    else if(field->getName() == "topMapId")
        m_topMapId = readDouble(field->getValue());
    
  }
}

