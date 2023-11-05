#include "MapReferenceData.h"

int MapReferenceData::getId() const
{
  return m_id;
}

double MapReferenceData::getMapId() const
{
  return m_mapId;
}

int MapReferenceData::getCellId() const
{
  return m_cellId;
}

void MapReferenceData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "mapId")
        m_mapId = readDouble(field->getValue());
    
    else if(field->getName() == "cellId")
        m_cellId = readInt(field->getValue());
    
  }
}

