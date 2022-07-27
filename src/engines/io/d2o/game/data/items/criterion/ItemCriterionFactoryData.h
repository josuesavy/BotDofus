#ifndef ITEMCRITERIONFACTORYDATA_H
#define ITEMCRITERIONFACTORYDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class ItemCriterionFactoryData : public AbstractGameData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // ITEMCRITERIONFACTORYDATA_H