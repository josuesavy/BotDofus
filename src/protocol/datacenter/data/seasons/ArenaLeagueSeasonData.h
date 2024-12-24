#ifndef ARENALEAGUESEASONDATA_H
#define ARENALEAGUESEASONDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class ArenaLeagueSeasonData : public AbstractGameData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // ARENALEAGUESEASONDATA_H