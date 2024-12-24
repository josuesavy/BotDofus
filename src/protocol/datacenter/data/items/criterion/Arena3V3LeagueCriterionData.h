#ifndef ARENA3V3LEAGUECRITERIONDATA_H
#define ARENA3V3LEAGUECRITERIONDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/items/criterion/ItemCriterionData.h"

class Arena3V3LeagueCriterionData : public ItemCriterionData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // ARENA3V3LEAGUECRITERIONDATA_H