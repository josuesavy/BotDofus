#ifndef PLAYLISTSOUNDDATA_H
#define PLAYLISTSOUNDDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class PlaylistSoundData : public AbstractGameData
{
public:
  QString getId() const;
  int getVolume() const;
  int getChannel() const;
  int getSoundOrder() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  QString m_id;
  int m_volume;
  int m_channel;
  int m_soundOrder;
};

#endif // PLAYLISTSOUNDDATA_H