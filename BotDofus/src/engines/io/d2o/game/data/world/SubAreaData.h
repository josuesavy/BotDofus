#ifndef SUBAREADATA_H
#define SUBAREADATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class SubAreaData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getAreaId() const;
  QList<QList<int>> getPlaylists() const;
  QList<double> getMapIds() const;
  QRect getBounds() const;
  QList<int> getShape() const;
  int getWorldmapId() const;
  QList<uint> getCustomWorldMap() const;
  int getPackId() const;
  uint getLevel() const;
  bool getIsConquestVillage() const;
  bool getBasicAccountAllowed() const;
  bool getDisplayOnWorldMap() const;
  bool getMountAutoTripAllowed() const;
  bool getPsiAllowed() const;
  QList<uint> getMonsters() const;
  QList<double> getEntranceMapIds() const;
  QList<double> getExitMapIds() const;
  bool getCapturable() const;
  QList<uint> getAchievements() const;
  QList<QList<double>> getQuests() const;
  QList<QList<double>> getNpcs() const;
  int getExploreAchievementId() const;
  bool getIsDiscovered() const;
  QList<int> getHarvestables() const;
  int getAssociatedZaapMapId() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_areaId;
  QList<QList<int>> m_playlists;
  QList<double> m_mapIds;
  QRect m_bounds;
  QList<int> m_shape;
  int m_worldmapId;
  QList<uint> m_customWorldMap;
  int m_packId;
  uint m_level;
  bool m_isConquestVillage;
  bool m_basicAccountAllowed;
  bool m_displayOnWorldMap;
  bool m_mountAutoTripAllowed;
  bool m_psiAllowed;
  QList<uint> m_monsters;
  QList<double> m_entranceMapIds;
  QList<double> m_exitMapIds;
  bool m_capturable;
  QList<uint> m_achievements;
  QList<QList<double>> m_quests;
  QList<QList<double>> m_npcs;
  int m_exploreAchievementId;
  bool m_isDiscovered;
  QList<int> m_harvestables;
  int m_associatedZaapMapId;
};

#endif // SUBAREADATA_H