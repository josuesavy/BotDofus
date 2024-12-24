#ifndef PLAYLISTDATA_H
#define PLAYLISTDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/ambientSounds/PlaylistSoundData.h"

class PlaylistData : public AbstractGameData
{
public:
  int getId() const;
  int getType() const;
  QList<PlaylistSoundData> getSounds() const;
  bool getStartRandom() const;
  bool getStartRandomOnce() const;
  int getCrossfadeDuration() const;
  bool getRandom() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  int m_type;
  QList<PlaylistSoundData> m_sounds;
  bool m_startRandom;
  bool m_startRandomOnce;
  int m_crossfadeDuration;
  bool m_random;
};

#endif // PLAYLISTDATA_H