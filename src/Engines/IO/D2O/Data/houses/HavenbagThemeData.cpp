#include "HavenbagThemeData.h"

int HavenbagThemeData::getId() const
{
  return m_id;
}

int HavenbagThemeData::getNameId() const
{
  return m_nameId;
}

double HavenbagThemeData::getMapId() const
{
  return m_mapId;
}

QString HavenbagThemeData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void HavenbagThemeData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readInt(field->getValue());
    
    else if(field->getName() == "mapId")
        m_mapId = readDouble(field->getValue());
    
  }
}

