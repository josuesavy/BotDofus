#ifndef ARENAMAX3V3LEAGUECRITERIONDATA_H
#define ARENAMAX3V3LEAGUECRITERIONDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/items/criterion/ItemCriterionData.h"

class ArenaMax3V3LeagueCriterionData : public ItemCriterionData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // ARENAMAX3V3LEAGUECRITERIONDATA_H