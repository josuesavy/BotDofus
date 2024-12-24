#ifndef ARENAMAX1V1LEAGUECRITERIONDATA_H
#define ARENAMAX1V1LEAGUECRITERIONDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/items/criterion/ItemCriterionData.h"

class ArenaMax1V1LeagueCriterionData : public ItemCriterionData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // ARENAMAX1V1LEAGUECRITERIONDATA_H