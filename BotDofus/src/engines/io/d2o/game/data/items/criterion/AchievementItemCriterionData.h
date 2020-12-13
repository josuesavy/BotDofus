#ifndef ACHIEVEMENTITEMCRITERIONDATA_H
#define ACHIEVEMENTITEMCRITERIONDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/items/criterion/ItemCriterionData.h"

class AchievementItemCriterionData : public ItemCriterionData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // ACHIEVEMENTITEMCRITERIONDATA_H