#ifndef ACHIEVEMENTPROGRESSDATA_H
#define ACHIEVEMENTPROGRESSDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"

class AchievementProgressData : public AbstractGameData
{
public:
  int getId() const;
  QString getName() const;
  int getSeasonId() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  QString m_name;
  int m_seasonId;
};

#endif // ACHIEVEMENTPROGRESSDATA_H