#ifndef QUESTSTEPREWARDSDATA_H
#define QUESTSTEPREWARDSDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class QuestStepRewardsData : public AbstractGameData
{
public:
  uint getId() const;
  uint getStepId() const;
  int getLevelMin() const;
  int getLevelMax() const;
  double getKamasRatio() const;
  double getExperienceRatio() const;
  bool getKamasScaleWithPlayerLevel() const;
  QList<QList<uint>> getItemsReward() const;
  QList<uint> getEmotesReward() const;
  QList<uint> getJobsReward() const;
  QList<uint> getSpellsReward() const;
  QList<uint> getTitlesReward() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_stepId;
  int m_levelMin;
  int m_levelMax;
  double m_kamasRatio;
  double m_experienceRatio;
  bool m_kamasScaleWithPlayerLevel;
  QList<QList<uint>> m_itemsReward;
  QList<uint> m_emotesReward;
  QList<uint> m_jobsReward;
  QList<uint> m_spellsReward;
  QList<uint> m_titlesReward;
};

#endif // QUESTSTEPREWARDSDATA_H