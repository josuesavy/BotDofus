#include "MapCoordinatesData.h"

uint MapCoordinatesData::getCompressedCoords() const
{
  return m_compressedCoords;
}

QList<double> MapCoordinatesData::getMapIds() const
{
  return m_mapIds;
}

void MapCoordinatesData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "compressedCoords")
        m_compressedCoords = readUInt(field->getValue());
    
    else if(field->getName() == "mapIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_mapIds << readDouble(data);
    }
    
  }
}

