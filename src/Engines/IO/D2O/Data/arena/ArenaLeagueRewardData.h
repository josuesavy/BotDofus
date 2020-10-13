#ifndef ARENALEAGUEREWARDDATA_H
#define ARENALEAGUEREWARDDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"

class ArenaLeagueRewardData : public AbstractGameData
{
public:
  int getId() const;
  uint getSeasonId() const;
  uint getLeagueId() const;
  QList<uint> getTitlesRewards() const;
  bool getEndSeasonRewards() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_seasonId;
  uint m_leagueId;
  QList<uint> m_titlesRewards;
  bool m_endSeasonRewards;
};

#endif // ARENALEAGUEREWARDDATA_H