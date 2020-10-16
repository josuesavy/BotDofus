#ifndef MAPPOSITIONDATA_H
#define MAPPOSITIONDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"

class MapPositionData : public AbstractGameData
{
public:
  double getId() const;
  int getPosX() const;
  int getPosY() const;
  bool getOutdoor() const;
  int getCapabilities() const;
  int getNameId() const;
  bool getShowNameOnFingerpost() const;
  QList<QList<int>> getPlaylists() const;
  int getSubAreaId() const;
  int getWorldMap() const;
  bool getHasPriorityOnWorldmap() const;
  bool getAllowPrism() const;
  bool getIsTransition() const;
  bool getMapHasTemplate() const;
  uint getTacticalModeTemplateId() const;
  bool getHasPublicPaddock() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  double m_id;
  int m_posX;
  int m_posY;
  bool m_outdoor;
  int m_capabilities;
  int m_nameId;
  bool m_showNameOnFingerpost;
  QList<QList<int>> m_playlists;
  int m_subAreaId;
  int m_worldMap;
  bool m_hasPriorityOnWorldmap;
  bool m_allowPrism;
  bool m_isTransition;
  bool m_mapHasTemplate;
  uint m_tacticalModeTemplateId;
  bool m_hasPublicPaddock;
};

#endif // MAPPOSITIONDATA_H