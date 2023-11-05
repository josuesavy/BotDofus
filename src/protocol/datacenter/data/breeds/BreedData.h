#ifndef BREEDDATA_H
#define BREEDDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class BreedData : public AbstractGameData
{
public:
  int getId() const;
  uint getShortNameId() const;
  uint getLongNameId() const;
  uint getDescriptionId() const;
  uint getGameplayDescriptionId() const;
  uint getGameplayClassDescriptionId() const;
  QString getMaleLook() const;
  QString getFemaleLook() const;
  uint getCreatureBonesId() const;
  int getMaleArtwork() const;
  int getFemaleArtwork() const;
  QList<QList<uint>> getStatsPointsForStrength() const;
  QList<QList<uint>> getStatsPointsForIntelligence() const;
  QList<QList<uint>> getStatsPointsForChance() const;
  QList<QList<uint>> getStatsPointsForAgility() const;
  QList<QList<uint>> getStatsPointsForVitality() const;
  QList<QList<uint>> getStatsPointsForWisdom() const;
  QList<uint> getBreedSpellsId() const;
  QList<uint> getMaleColors() const;
  QList<uint> getFemaleColors() const;
  uint getSpawnMap() const;
  uint getComplexity() const;
  uint getSortIndex() const;
  QString getShortName() const;
  QString getLongName() const;
  QString getDescription() const;
  QString getGameplayDescription() const;
  QString getGameplayClassDescription() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_shortNameId;
  uint m_longNameId;
  uint m_descriptionId;
  uint m_gameplayDescriptionId;
  uint m_gameplayClassDescriptionId;
  QString m_maleLook;
  QString m_femaleLook;
  uint m_creatureBonesId;
  int m_maleArtwork;
  int m_femaleArtwork;
  QList<QList<uint>> m_statsPointsForStrength;
  QList<QList<uint>> m_statsPointsForIntelligence;
  QList<QList<uint>> m_statsPointsForChance;
  QList<QList<uint>> m_statsPointsForAgility;
  QList<QList<uint>> m_statsPointsForVitality;
  QList<QList<uint>> m_statsPointsForWisdom;
  QList<uint> m_breedSpellsId;
  QList<uint> m_maleColors;
  QList<uint> m_femaleColors;
  uint m_spawnMap;
  uint m_complexity;
  uint m_sortIndex;
};

#endif // BREEDDATA_H