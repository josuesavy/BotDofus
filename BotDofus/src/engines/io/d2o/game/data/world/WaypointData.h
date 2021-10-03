#ifndef WAYPOINTDATA_H
#define WAYPOINTDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class WaypointData : public AbstractGameData
{
public:
  uint getId() const;
  double getMapId() const;
  uint getSubAreaId() const;
  bool getActivated() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  double m_mapId;
  uint m_subAreaId;
  bool m_activated;
};

#endif // WAYPOINTDATA_H