#include "BoundScriptUsageDataData.h"

int BoundScriptUsageDataData::getId() const
{
  return m_id;
}

int BoundScriptUsageDataData::getScriptId() const
{
  return m_scriptId;
}

QList<uint> BoundScriptUsageDataData::getSpellLevels() const
{
  return m_spellLevels;
}

QString BoundScriptUsageDataData::getCriterion() const
{
  return m_criterion;
}

QString BoundScriptUsageDataData::getCasterMask() const
{
  return m_casterMask;
}

QString BoundScriptUsageDataData::getTargetMask() const
{
  return m_targetMask;
}

QString BoundScriptUsageDataData::getTargetZone() const
{
  return m_targetZone;
}

QString BoundScriptUsageDataData::getActivationMask() const
{
  return m_activationMask;
}

QString BoundScriptUsageDataData::getActivationZone() const
{
  return m_activationZone;
}

int BoundScriptUsageDataData::getRandom() const
{
  return m_random;
}

int BoundScriptUsageDataData::getRandomGroup() const
{
  return m_randomGroup;
}

void BoundScriptUsageDataData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "scriptId")
        m_scriptId = readInt(field->getValue());
    
    else if(field->getName() == "spellLevels")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_spellLevels << readUInt(data);
    }
    
    else if(field->getName() == "criterion")
        m_criterion = readUTF(field->getValue());
    
    else if(field->getName() == "casterMask")
        m_casterMask = readUTF(field->getValue());
    
    else if(field->getName() == "targetMask")
        m_targetMask = readUTF(field->getValue());
    
    else if(field->getName() == "targetZone")
        m_targetZone = readUTF(field->getValue());
    
    else if(field->getName() == "activationMask")
        m_activationMask = readUTF(field->getValue());
    
    else if(field->getName() == "activationZone")
        m_activationZone = readUTF(field->getValue());
    
    else if(field->getName() == "random")
        m_random = readInt(field->getValue());
    
    else if(field->getName() == "randomGroup")
        m_randomGroup = readInt(field->getValue());
    
  }
}

