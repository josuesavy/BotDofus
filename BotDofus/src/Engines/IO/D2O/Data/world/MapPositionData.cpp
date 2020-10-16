#include "MapPositionData.h"

double MapPositionData::getId() const
{
  return m_id;
}

int MapPositionData::getPosX() const
{
  return m_posX;
}

int MapPositionData::getPosY() const
{
  return m_posY;
}

bool MapPositionData::getOutdoor() const
{
  return m_outdoor;
}

int MapPositionData::getCapabilities() const
{
  return m_capabilities;
}

int MapPositionData::getNameId() const
{
  return m_nameId;
}

bool MapPositionData::getShowNameOnFingerpost() const
{
  return m_showNameOnFingerpost;
}

QList<QList<int>> MapPositionData::getPlaylists() const
{
  return m_playlists;
}

int MapPositionData::getSubAreaId() const
{
  return m_subAreaId;
}

int MapPositionData::getWorldMap() const
{
  return m_worldMap;
}

bool MapPositionData::getHasPriorityOnWorldmap() const
{
  return m_hasPriorityOnWorldmap;
}

bool MapPositionData::getAllowPrism() const
{
  return m_allowPrism;
}

bool MapPositionData::getIsTransition() const
{
  return m_isTransition;
}

bool MapPositionData::getMapHasTemplate() const
{
  return m_mapHasTemplate;
}

uint MapPositionData::getTacticalModeTemplateId() const
{
  return m_tacticalModeTemplateId;
}

bool MapPositionData::getHasPublicPaddock() const
{
  return m_hasPublicPaddock;
}

QString MapPositionData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void MapPositionData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readDouble(field->getValue());
    
    else if(field->getName() == "posX")
        m_posX = readInt(field->getValue());
    
    else if(field->getName() == "posY")
        m_posY = readInt(field->getValue());
    
    else if(field->getName() == "outdoor")
        m_outdoor = readBool(field->getValue());
    
    else if(field->getName() == "capabilities")
        m_capabilities = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readInt(field->getValue());
    
    else if(field->getName() == "showNameOnFingerpost")
        m_showNameOnFingerpost = readBool(field->getValue());
    
    else if(field->getName() == "playlists")
    {
      foreach(const QByteArray &firstList, readVector(field->getValue()))
      {
        QList<int> secondList;
        
        foreach (const QByteArray &data, readVector(firstList))
            secondList << readInt(data);
        
        m_playlists << secondList;
      }
    }
    
    else if(field->getName() == "subAreaId")
        m_subAreaId = readInt(field->getValue());
    
    else if(field->getName() == "worldMap")
        m_worldMap = readInt(field->getValue());
    
    else if(field->getName() == "hasPriorityOnWorldmap")
        m_hasPriorityOnWorldmap = readBool(field->getValue());
    
    else if(field->getName() == "allowPrism")
        m_allowPrism = readBool(field->getValue());
    
    else if(field->getName() == "isTransition")
        m_isTransition = readBool(field->getValue());
    
    else if(field->getName() == "mapHasTemplate")
        m_mapHasTemplate = readBool(field->getValue());
    
    else if(field->getName() == "tacticalModeTemplateId")
        m_tacticalModeTemplateId = readUInt(field->getValue());
    
    else if(field->getName() == "hasPublicPaddock")
        m_hasPublicPaddock = readBool(field->getValue());
    
  }
}

