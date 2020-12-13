#ifndef SEXITEMCRITERIONDATA_H
#define SEXITEMCRITERIONDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/items/criterion/ItemCriterionData.h"

class SexItemCriterionData : public ItemCriterionData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // SEXITEMCRITERIONDATA_H