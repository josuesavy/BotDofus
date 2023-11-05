#include "SoundBonesData.h"

QString SoundBonesData::getMODULE() const
{
  return m_MODULE;
}

uint SoundBonesData::getId() const
{
  return m_id;
}

QList<QString> SoundBonesData::getKeys() const
{
  return m_keys;
}

void SoundBonesData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "MODULE")
        m_MODULE = readUTF(field->getValue());
    
    else if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "keys")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_keys << readUTF(data);
    }
    
  }
}

