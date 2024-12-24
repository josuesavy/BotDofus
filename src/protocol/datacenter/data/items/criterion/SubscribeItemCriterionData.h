#ifndef SUBSCRIBEITEMCRITERIONDATA_H
#define SUBSCRIBEITEMCRITERIONDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/items/criterion/ItemCriterionData.h"

class SubscribeItemCriterionData : public ItemCriterionData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // SUBSCRIBEITEMCRITERIONDATA_H