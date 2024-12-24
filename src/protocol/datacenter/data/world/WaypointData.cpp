#include "WaypointData.h"

uint WaypointData::getId() const
{
  return m_id;
}

double WaypointData::getMapId() const
{
  return m_mapId;
}

uint WaypointData::getSubAreaId() const
{
  return m_subAreaId;
}

bool WaypointData::getActivated() const
{
  return m_activated;
}

void WaypointData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "mapId")
        m_mapId = readDouble(field->getValue());
    
    else if(field->getName() == "subAreaId")
        m_subAreaId = readUInt(field->getValue());
    
    else if(field->getName() == "activated")
        m_activated = readBool(field->getValue());
    
  }
}

