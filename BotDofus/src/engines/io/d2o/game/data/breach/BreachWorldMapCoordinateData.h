#ifndef BREACHWORLDMAPCOORDINATEDATA_H
#define BREACHWORLDMAPCOORDINATEDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"

class BreachWorldMapCoordinateData : public AbstractGameData
{
public:
  uint getId() const;
  uint getMapStage() const;
  int getMapCoordinateX() const;
  int getMapCoordinateY() const;
  int getUnexploredMapIcon() const;
  int getExploredMapIcon() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_mapStage;
  int m_mapCoordinateX;
  int m_mapCoordinateY;
  int m_unexploredMapIcon;
  int m_exploredMapIcon;
};

#endif // BREACHWORLDMAPCOORDINATEDATA_H