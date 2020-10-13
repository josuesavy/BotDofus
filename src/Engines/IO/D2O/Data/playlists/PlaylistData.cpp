#include "PlaylistData.h"

int PlaylistData::getId() const
{
  return m_id;
}

int PlaylistData::getType() const
{
  return m_type;
}

QList<PlaylistSoundData> PlaylistData::getSounds() const
{
  return m_sounds;
}

bool PlaylistData::getStartRandom() const
{
  return m_startRandom;
}

bool PlaylistData::getStartRandomOnce() const
{
  return m_startRandomOnce;
}

int PlaylistData::getCrossfadeDuration() const
{
  return m_crossfadeDuration;
}

bool PlaylistData::getRandom() const
{
  return m_random;
}

void PlaylistData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "type")
        m_type = readInt(field->getValue());
    
    else if(field->getName() == "sounds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_sounds << *qSharedPointerCast<PlaylistSoundData>(readObject(data, field)).data();
    }
    
    else if(field->getName() == "startRandom")
        m_startRandom = readBool(field->getValue());
    
    else if(field->getName() == "startRandomOnce")
        m_startRandomOnce = readBool(field->getValue());
    
    else if(field->getName() == "crossfadeDuration")
        m_crossfadeDuration = readInt(field->getValue());
    
    else if(field->getName() == "random")
        m_random = readBool(field->getValue());
    
  }
}

