#ifndef BREACHDUNGEONMODIFICATORDATA_H
#define BREACHDUNGEONMODIFICATORDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class BreachDungeonModificatorData : public AbstractGameData
{
public:
  uint getId() const;
  uint getModificatorId() const;
  QString getCriterion() const;
  double getAdditionalRewardPercent() const;
  double getScore() const;
  bool getIsPositiveForPlayers() const;
  QString getTooltipBaseline() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_modificatorId;
  QString m_criterion;
  double m_additionalRewardPercent;
  double m_score;
  bool m_isPositiveForPlayers;
  QString m_tooltipBaseline;
};

#endif // BREACHDUNGEONMODIFICATORDATA_H