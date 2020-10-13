#ifndef PREMIUMACCOUNTITEMCRITERIONDATA_H
#define PREMIUMACCOUNTITEMCRITERIONDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/ItemCriterionData.h"

class PremiumAccountItemCriterionData : public ItemCriterionData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // PREMIUMACCOUNTITEMCRITERIONDATA_H