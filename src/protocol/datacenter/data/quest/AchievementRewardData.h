#ifndef ACHIEVEMENTREWARDDATA_H
#define ACHIEVEMENTREWARDDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class AchievementRewardData : public AbstractGameData
{
public:
  uint getId() const;
  uint getAchievementId() const;
  QString getCriteria() const;
  double getKamasRatio() const;
  double getExperienceRatio() const;
  bool getKamasScaleWithPlayerLevel() const;
  QList<uint> getItemsReward() const;
  QList<uint> getItemsQuantityReward() const;
  QList<uint> getEmotesReward() const;
  QList<uint> getSpellsReward() const;
  QList<uint> getTitlesReward() const;
  QList<uint> getOrnamentsReward() const;
  uint getGuildPoints() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_achievementId;
  QString m_criteria;
  double m_kamasRatio;
  double m_experienceRatio;
  bool m_kamasScaleWithPlayerLevel;
  QList<uint> m_itemsReward;
  QList<uint> m_itemsQuantityReward;
  QList<uint> m_emotesReward;
  QList<uint> m_spellsReward;
  QList<uint> m_titlesReward;
  QList<uint> m_ornamentsReward;
  uint m_guildPoints;
};

#endif // ACHIEVEMENTREWARDDATA_H