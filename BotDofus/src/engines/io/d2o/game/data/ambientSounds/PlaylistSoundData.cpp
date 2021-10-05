#include "PlaylistSoundData.h"

QString PlaylistSoundData::getId() const
{
  return m_id;
}

int PlaylistSoundData::getVolume() const
{
  return m_volume;
}

int PlaylistSoundData::getChannel() const
{
  return m_channel;
}

int PlaylistSoundData::getSoundOrder() const
{
  return m_soundOrder;
}

void PlaylistSoundData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUTF(field->getValue());
    
    else if(field->getName() == "volume")
        m_volume = readInt(field->getValue());
    
    else if(field->getName() == "channel")
        m_channel = readInt(field->getValue());
    
    else if(field->getName() == "soundOrder")
        m_soundOrder = readInt(field->getValue());
    
  }
}

