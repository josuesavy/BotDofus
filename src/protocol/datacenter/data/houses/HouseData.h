#ifndef HOUSEDATA_H
#define HOUSEDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class HouseData : public AbstractGameData
{
public:
  int getTypeId() const;
  uint getDefaultPrice() const;
  int getNameId() const;
  int getDescriptionId() const;
  int getGfxId() const;
  QString getName() const;
  QString getDescription() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_typeId;
  uint m_defaultPrice;
  int m_nameId;
  int m_descriptionId;
  int m_gfxId;
};

#endif // HOUSEDATA_H