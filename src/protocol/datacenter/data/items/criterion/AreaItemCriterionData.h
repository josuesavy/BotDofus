#ifndef AREAITEMCRITERIONDATA_H
#define AREAITEMCRITERIONDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/items/criterion/ItemCriterionData.h"

class AreaItemCriterionData : public ItemCriterionData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // AREAITEMCRITERIONDATA_H