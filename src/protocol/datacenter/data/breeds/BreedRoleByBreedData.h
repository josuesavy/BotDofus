#ifndef BREEDROLEBYBREEDDATA_H
#define BREEDROLEBYBREEDDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class BreedRoleByBreedData : public AbstractGameData
{
public:
  int getBreedId() const;
  int getRoleId() const;
  uint getDescriptionId() const;
  int getValue() const;
  int getOrder() const;
  QString getDescription() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_breedId;
  int m_roleId;
  uint m_descriptionId;
  int m_value;
  int m_order;
};

#endif // BREEDROLEBYBREEDDATA_H