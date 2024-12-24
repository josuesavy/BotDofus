#ifndef GROUPITEMCRITERIONDATA_H
#define GROUPITEMCRITERIONDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class GroupItemCriterionData : public AbstractGameData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // GROUPITEMCRITERIONDATA_H