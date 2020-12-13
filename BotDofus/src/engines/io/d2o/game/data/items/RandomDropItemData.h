#ifndef RANDOMDROPITEMDATA_H
#define RANDOMDROPITEMDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"

class RandomDropItemData : public AbstractGameData
{
public:
  uint getId() const;
  uint getItemId() const;
  double getProbability() const;
  uint getMinQuantity() const;
  uint getMaxQuantity() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_itemId;
  double m_probability;
  uint m_minQuantity;
  uint m_maxQuantity;
};

#endif // RANDOMDROPITEMDATA_H