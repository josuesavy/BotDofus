#include "BreachWorldMapSectorData.h"

uint BreachWorldMapSectorData::getId() const
{
  return m_id;
}

uint BreachWorldMapSectorData::getSectorNameId() const
{
  return m_sectorNameId;
}

uint BreachWorldMapSectorData::getLegendId() const
{
  return m_legendId;
}

QString BreachWorldMapSectorData::getSectorIcon() const
{
  return m_sectorIcon;
}

int BreachWorldMapSectorData::getMinStage() const
{
  return m_minStage;
}

int BreachWorldMapSectorData::getMaxStage() const
{
  return m_maxStage;
}

QString BreachWorldMapSectorData::getLegend() const
{
  return m_I18n->getText(m_legendId);
}

void BreachWorldMapSectorData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "sectorNameId")
        m_sectorNameId = readUInt(field->getValue());
    
    else if(field->getName() == "legendId")
        m_legendId = readUInt(field->getValue());
    
    else if(field->getName() == "sectorIcon")
        m_sectorIcon = readUTF(field->getValue());
    
    else if(field->getName() == "minStage")
        m_minStage = readInt(field->getValue());
    
    else if(field->getName() == "maxStage")
        m_maxStage = readInt(field->getValue());
    
  }
}

