#ifndef SUBSCRIBEITEMCRITERIONDATA_H
#define SUBSCRIBEITEMCRITERIONDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/items/criterion/ItemCriterionData.h"

class SubscribeItemCriterionData : public ItemCriterionData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // SUBSCRIBEITEMCRITERIONDATA_H