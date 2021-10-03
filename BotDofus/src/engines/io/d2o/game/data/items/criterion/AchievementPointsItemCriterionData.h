#ifndef ACHIEVEMENTPOINTSITEMCRITERIONDATA_H
#define ACHIEVEMENTPOINTSITEMCRITERIONDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/items/criterion/ItemCriterionData.h"

class AchievementPointsItemCriterionData : public ItemCriterionData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // ACHIEVEMENTPOINTSITEMCRITERIONDATA_H