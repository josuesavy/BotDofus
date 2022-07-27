#include "DungeonData.h"

int DungeonData::getId() const
{
  return m_id;
}

uint DungeonData::getNameId() const
{
  return m_nameId;
}

int DungeonData::getOptimalPlayerLevel() const
{
  return m_optimalPlayerLevel;
}

QList<double> DungeonData::getMapIds() const
{
  return m_mapIds;
}

double DungeonData::getEntranceMapId() const
{
  return m_entranceMapId;
}

double DungeonData::getExitMapId() const
{
  return m_exitMapId;
}

QString DungeonData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void DungeonData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "optimalPlayerLevel")
        m_optimalPlayerLevel = readInt(field->getValue());
    
    else if(field->getName() == "mapIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_mapIds << readDouble(data);
    }
    
    else if(field->getName() == "entranceMapId")
        m_entranceMapId = readDouble(field->getValue());
    
    else if(field->getName() == "exitMapId")
        m_exitMapId = readDouble(field->getValue());
    
  }
}

