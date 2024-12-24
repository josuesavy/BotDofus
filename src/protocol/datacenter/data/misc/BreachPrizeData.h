#ifndef BREACHPRIZEDATA_H
#define BREACHPRIZEDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class BreachPrizeData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getCurrency() const;
  QString getTooltipKey() const;
  uint getDescriptionKey() const;
  int getCategoryId() const;
  int getItemId() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_currency;
  QString m_tooltipKey;
  uint m_descriptionKey;
  int m_categoryId;
  int m_itemId;
};

#endif // BREACHPRIZEDATA_H