#ifndef BONUSCRITERIONDATA_H
#define BONUSCRITERIONDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"

class BonusCriterionData : public AbstractGameData
{
public:
  int getId() const;
  uint getType() const;
  int getValue() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_type;
  int m_value;
};

#endif // BONUSCRITERIONDATA_H