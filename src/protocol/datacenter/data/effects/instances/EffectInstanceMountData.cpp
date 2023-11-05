#include "EffectInstanceMountData.h"

double EffectInstanceMountData::getId() const
{
  return m_id;
}

double EffectInstanceMountData::getExpirationDate() const
{
  return m_expirationDate;
}

uint EffectInstanceMountData::getModel() const
{
  return m_model;
}

QString EffectInstanceMountData::getName() const
{
  return m_name;
}

QString EffectInstanceMountData::getOwner() const
{
  return m_owner;
}

uint EffectInstanceMountData::getLevel() const
{
  return m_level;
}

bool EffectInstanceMountData::getSex() const
{
  return m_sex;
}

bool EffectInstanceMountData::getIsRideable() const
{
  return m_isRideable;
}

bool EffectInstanceMountData::getIsFeconded() const
{
  return m_isFeconded;
}

bool EffectInstanceMountData::getIsFecondationReady() const
{
  return m_isFecondationReady;
}

int EffectInstanceMountData::getReproductionCount() const
{
  return m_reproductionCount;
}

uint EffectInstanceMountData::getReproductionCountMax() const
{
  return m_reproductionCountMax;
}

QList<uint> EffectInstanceMountData::getCapacities() const
{
  return m_capacities;
}

void EffectInstanceMountData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  EffectInstanceData::loadData(fields, I18n);
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readDouble(field->getValue());
    
    else if(field->getName() == "expirationDate")
        m_expirationDate = readDouble(field->getValue());
    
    else if(field->getName() == "model")
        m_model = readUInt(field->getValue());
    
    else if(field->getName() == "name")
        m_name = readUTF(field->getValue());
    
    else if(field->getName() == "owner")
        m_owner = readUTF(field->getValue());
    
    else if(field->getName() == "level")
        m_level = readUInt(field->getValue());
    
    else if(field->getName() == "sex")
        m_sex = readBool(field->getValue());
    
    else if(field->getName() == "isRideable")
        m_isRideable = readBool(field->getValue());
    
    else if(field->getName() == "isFeconded")
        m_isFeconded = readBool(field->getValue());
    
    else if(field->getName() == "isFecondationReady")
        m_isFecondationReady = readBool(field->getValue());
    
    else if(field->getName() == "reproductionCount")
        m_reproductionCount = readInt(field->getValue());
    
    else if(field->getName() == "reproductionCountMax")
        m_reproductionCountMax = readUInt(field->getValue());
    
    else if(field->getName() == "capacities")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_capacities << readUInt(data);
    }
    
  }
}

