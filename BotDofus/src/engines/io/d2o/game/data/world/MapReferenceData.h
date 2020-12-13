#ifndef MAPREFERENCEDATA_H
#define MAPREFERENCEDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"

class MapReferenceData : public AbstractGameData
{
public:
  int getId() const;
  double getMapId() const;
  int getCellId() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  double m_mapId;
  int m_cellId;
};

#endif // MAPREFERENCEDATA_H