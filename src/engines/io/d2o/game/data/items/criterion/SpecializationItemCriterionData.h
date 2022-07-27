#ifndef SPECIALIZATIONITEMCRITERIONDATA_H
#define SPECIALIZATIONITEMCRITERIONDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/items/criterion/ItemCriterionData.h"

class SpecializationItemCriterionData : public ItemCriterionData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // SPECIALIZATIONITEMCRITERIONDATA_H