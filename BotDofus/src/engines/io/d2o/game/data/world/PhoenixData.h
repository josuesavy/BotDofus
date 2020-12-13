#ifndef PHOENIXDATA_H
#define PHOENIXDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"

class PhoenixData : public AbstractGameData
{
public:
  double getMapId() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  double m_mapId;
};

#endif // PHOENIXDATA_H