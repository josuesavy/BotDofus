#ifndef ALIGNMENTRANKDATA_H
#define ALIGNMENTRANKDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class AlignmentRankData : public AbstractGameData
{
public:
  int getId() const;
  uint getOrderId() const;
  uint getNameId() const;
  uint getDescriptionId() const;
  int getMinimumAlignment() const;
  QList<int> getGifts() const;
  QString getName() const;
  QString getDescription() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_orderId;
  uint m_nameId;
  uint m_descriptionId;
  int m_minimumAlignment;
  QList<int> m_gifts;
};

#endif // ALIGNMENTRANKDATA_H