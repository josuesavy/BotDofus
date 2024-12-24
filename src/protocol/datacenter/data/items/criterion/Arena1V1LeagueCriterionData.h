#ifndef ARENA1V1LEAGUECRITERIONDATA_H
#define ARENA1V1LEAGUECRITERIONDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/items/criterion/ItemCriterionData.h"

class Arena1V1LeagueCriterionData : public ItemCriterionData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // ARENA1V1LEAGUECRITERIONDATA_H