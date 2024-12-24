#ifndef ITEMTYPEDATA_H
#define ITEMTYPEDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class ItemTypeData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  uint getSuperTypeId() const;
  uint getCategoryId() const;
  bool getIsInEncyclopedia() const;
  bool getPlural() const;
  uint getGender() const;
  QString getRawZone() const;
  bool getMimickable() const;
  int getCraftXpRatio() const;
  int getEvolutiveTypeId() const;
  QList<int> getPossiblePositions() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  uint m_superTypeId;
  uint m_categoryId;
  bool m_isInEncyclopedia;
  bool m_plural;
  uint m_gender;
  QString m_rawZone;
  bool m_mimickable;
  int m_craftXpRatio;
  int m_evolutiveTypeId;
  QList<int> m_possiblePositions;
};

#endif // ITEMTYPEDATA_H