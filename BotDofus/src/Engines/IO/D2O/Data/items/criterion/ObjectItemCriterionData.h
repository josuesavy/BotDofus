#ifndef OBJECTITEMCRITERIONDATA_H
#define OBJECTITEMCRITERIONDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/ItemCriterionData.h"

class ObjectItemCriterionData : public ItemCriterionData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // OBJECTITEMCRITERIONDATA_H