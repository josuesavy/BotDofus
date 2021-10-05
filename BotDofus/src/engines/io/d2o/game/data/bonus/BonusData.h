#ifndef BONUSDATA_H
#define BONUSDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class BonusData : public AbstractGameData
{
public:
  int getId() const;
  uint getType() const;
  int getAmount() const;
  QList<int> getCriterionsIds() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_type;
  int m_amount;
  QList<int> m_criterionsIds;
};

#endif // BONUSDATA_H