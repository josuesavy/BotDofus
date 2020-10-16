#include "PhoenixData.h"

double PhoenixData::getMapId() const
{
  return m_mapId;
}

void PhoenixData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "mapId")
        m_mapId = readDouble(field->getValue());
    
  }
}

