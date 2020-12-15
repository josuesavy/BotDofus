#ifndef GROUPITEMCRITERIONDATA_H
#define GROUPITEMCRITERIONDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class GroupItemCriterionData : public AbstractGameData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // GROUPITEMCRITERIONDATA_H