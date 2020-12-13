#ifndef MARIEDITEMCRITERIONDATA_H
#define MARIEDITEMCRITERIONDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/items/criterion/ItemCriterionData.h"

class MariedItemCriterionData : public ItemCriterionData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // MARIEDITEMCRITERIONDATA_H