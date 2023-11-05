#include "BreachWorldMapCoordinateData.h"

uint BreachWorldMapCoordinateData::getId() const
{
  return m_id;
}

uint BreachWorldMapCoordinateData::getMapStage() const
{
  return m_mapStage;
}

int BreachWorldMapCoordinateData::getMapCoordinateX() const
{
  return m_mapCoordinateX;
}

int BreachWorldMapCoordinateData::getMapCoordinateY() const
{
  return m_mapCoordinateY;
}

int BreachWorldMapCoordinateData::getUnexploredMapIcon() const
{
  return m_unexploredMapIcon;
}

int BreachWorldMapCoordinateData::getExploredMapIcon() const
{
  return m_exploredMapIcon;
}

void BreachWorldMapCoordinateData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "mapStage")
        m_mapStage = readUInt(field->getValue());
    
    else if(field->getName() == "mapCoordinateX")
        m_mapCoordinateX = readInt(field->getValue());
    
    else if(field->getName() == "mapCoordinateY")
        m_mapCoordinateY = readInt(field->getValue());
    
    else if(field->getName() == "unexploredMapIcon")
        m_unexploredMapIcon = readInt(field->getValue());
    
    else if(field->getName() == "exploredMapIcon")
        m_exploredMapIcon = readInt(field->getValue());
    
  }
}

