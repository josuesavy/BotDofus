#ifndef ABUSEREASONSDATA_H
#define ABUSEREASONSDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class AbuseReasonsData : public AbstractGameData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // ABUSEREASONSDATA_H