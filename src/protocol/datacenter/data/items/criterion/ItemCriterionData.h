#ifndef ITEMCRITERIONDATA_H
#define ITEMCRITERIONDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class ItemCriterionData : public AbstractGameData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // ITEMCRITERIONDATA_H