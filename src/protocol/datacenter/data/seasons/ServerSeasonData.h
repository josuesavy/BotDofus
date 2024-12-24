#ifndef SERVERSEASONDATA_H
#define SERVERSEASONDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class ServerSeasonData : public AbstractGameData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // SERVERSEASONDATA_H