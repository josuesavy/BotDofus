#ifndef SUBAREADATA_H
#define SUBAREADATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class SubAreaData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getAreaId() const;
  QList<QList<int>> getPlaylists() const;
  QList<double> getMapIds() const;
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
  bool getCapturable() const;
  QList<QList<double>> getQuests() const;
  QList<QList<double>> getNpcs() const;
  QList<int> getHarvestables() const;
  QList<int> getNeighbors() const;
  int getAssociatedZaapMapId() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_areaId;
  QList<QList<int>> m_playlists;
  QList<double> m_mapIds;
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
  bool m_capturable;
  QList<QList<double>> m_quests;
  QList<QList<double>> m_npcs;
  QList<int> m_harvestables;
  QList<int> m_neighbors;
  int m_associatedZaapMapId;
};

#endif // SUBAREADATA_H