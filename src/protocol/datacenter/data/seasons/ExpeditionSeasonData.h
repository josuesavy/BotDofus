#ifndef EXPEDITIONSEASONDATA_H
#define EXPEDITIONSEASONDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class ExpeditionSeasonData : public AbstractGameData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // EXPEDITIONSEASONDATA_H