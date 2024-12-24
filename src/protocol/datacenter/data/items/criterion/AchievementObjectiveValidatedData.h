#ifndef ACHIEVEMENTOBJECTIVEVALIDATEDDATA_H
#define ACHIEVEMENTOBJECTIVEVALIDATEDDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/items/criterion/ItemCriterionData.h"

class AchievementObjectiveValidatedData : public ItemCriterionData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // ACHIEVEMENTOBJECTIVEVALIDATEDDATA_H