#ifndef SUBSCRIPTIONDURATIONITEMCRITERIONDATA_H
#define SUBSCRIPTIONDURATIONITEMCRITERIONDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/ItemCriterionData.h"

class SubscriptionDurationItemCriterionData : public ItemCriterionData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // SUBSCRIPTIONDURATIONITEMCRITERIONDATA_H