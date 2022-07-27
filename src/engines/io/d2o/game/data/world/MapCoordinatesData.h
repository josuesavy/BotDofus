#ifndef MAPCOORDINATESDATA_H
#define MAPCOORDINATESDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class MapCoordinatesData : public AbstractGameData
{
public:
  uint getCompressedCoords() const;
  QList<double> getMapIds() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_compressedCoords;
  QList<double> m_mapIds;
};

#endif // MAPCOORDINATESDATA_H