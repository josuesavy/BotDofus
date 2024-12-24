#ifndef ARENAMAX2V2LEAGUECRITERIONDATA_H
#define ARENAMAX2V2LEAGUECRITERIONDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/items/criterion/ItemCriterionData.h"

class ArenaMax2V2LeagueCriterionData : public ItemCriterionData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // ARENAMAX2V2LEAGUECRITERIONDATA_H