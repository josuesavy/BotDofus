#ifndef ALIGNMENTRANKDATA_H
#define ALIGNMENTRANKDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class AlignmentRankData : public AbstractGameData
{
public:
  int getId() const;
  uint getOrderId() const;
  uint getNameId() const;
  uint getDescriptionId() const;
  int getMinimumAlignment() const;
  int getObjectsStolen() const;
  QList<int> getGifts() const;
  QString getName() const;
  QString getDescription() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_orderId;
  uint m_nameId;
  uint m_descriptionId;
  int m_minimumAlignment;
  int m_objectsStolen;
  QList<int> m_gifts;
};

#endif // ALIGNMENTRANKDATA_H