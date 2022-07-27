#ifndef WORLDMAPDATA_H
#define WORLDMAPDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class WorldMapData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getOrigineX() const;
  int getOrigineY() const;
  double getMapWidth() const;
  double getMapHeight() const;
  bool getViewableEverywhere() const;
  double getMinScale() const;
  double getMaxScale() const;
  double getStartScale() const;
  int getTotalWidth() const;
  int getTotalHeight() const;
  QList<QString> getZoom() const;
  bool getVisibleOnMap() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_origineX;
  int m_origineY;
  double m_mapWidth;
  double m_mapHeight;
  bool m_viewableEverywhere;
  double m_minScale;
  double m_maxScale;
  double m_startScale;
  int m_totalWidth;
  int m_totalHeight;
  QList<QString> m_zoom;
  bool m_visibleOnMap;
};

#endif // WORLDMAPDATA_H