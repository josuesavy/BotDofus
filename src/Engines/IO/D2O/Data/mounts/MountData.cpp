#include "MountData.h"

uint MountData::getId() const
{
  return m_id;
}

uint MountData::getFamilyId() const
{
  return m_familyId;
}

uint MountData::getNameId() const
{
  return m_nameId;
}

QString MountData::getLook() const
{
  return m_look;
}

uint MountData::getCertificateId() const
{
  return m_certificateId;
}

QList<EffectInstanceData> MountData::getEffects() const
{
  return m_effects;
}

QString MountData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void MountData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "familyId")
        m_familyId = readUInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "look")
        m_look = readUTF(field->getValue());
    
    else if(field->getName() == "certificateId")
        m_certificateId = readUInt(field->getValue());
    
    else if(field->getName() == "effects")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_effects << *qSharedPointerCast<EffectInstanceData>(readObject(data, field)).data();
    }
    
  }
}

