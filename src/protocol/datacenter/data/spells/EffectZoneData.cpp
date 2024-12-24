#include "EffectZoneData.h"

uint EffectZoneData::getId() const
{
  return m_id;
}

bool EffectZoneData::getIsDefaultPreviewZoneHidden() const
{
  return m_isDefaultPreviewZoneHidden;
}

QString EffectZoneData::getCasterMask() const
{
  return m_casterMask;
}

QString EffectZoneData::getActivationMask() const
{
  return m_activationMask;
}

void EffectZoneData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "isDefaultPreviewZoneHidden")
        m_isDefaultPreviewZoneHidden = readBool(field->getValue());
    
    else if(field->getName() == "casterMask")
        m_casterMask = readUTF(field->getValue());
    
    else if(field->getName() == "activationMask")
        m_activationMask = readUTF(field->getValue());
    
  }
}

