#ifndef COMMUNITYITEMCRITERIONDATA_H
#define COMMUNITYITEMCRITERIONDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/items/criterion/ItemCriterionData.h"

class CommunityItemCriterionData : public ItemCriterionData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // COMMUNITYITEMCRITERIONDATA_H