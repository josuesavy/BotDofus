#ifndef CRITERIONUTILSDATA_H
#define CRITERIONUTILSDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class CriterionUtilsData : public AbstractGameData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // CRITERIONUTILSDATA_H