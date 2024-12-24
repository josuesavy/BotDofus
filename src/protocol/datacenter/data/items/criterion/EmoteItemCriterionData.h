#ifndef EMOTEITEMCRITERIONDATA_H
#define EMOTEITEMCRITERIONDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/items/criterion/ItemCriterionData.h"

class EmoteItemCriterionData : public ItemCriterionData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // EMOTEITEMCRITERIONDATA_H