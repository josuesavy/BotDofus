#ifndef ACHIEVEMENTPROGRESSSTEPDATA_H
#define ACHIEVEMENTPROGRESSSTEPDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class AchievementProgressStepData : public AbstractGameData
{
public:
  int getId() const;
  int getProgressId() const;
  int getScore() const;
  bool getIsCosmetic() const;
  int getAchievementId() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  int m_progressId;
  int m_score;
  bool m_isCosmetic;
  int m_achievementId;
};

#endif // ACHIEVEMENTPROGRESSSTEPDATA_H