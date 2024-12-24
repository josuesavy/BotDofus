#ifndef EVOLUTIVEITEMTYPEDATA_H
#define EVOLUTIVEITEMTYPEDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class EvolutiveItemTypeData : public AbstractGameData
{
public:
  int getId() const;
  uint getMaxLevel() const;
  double getExperienceBoost() const;
  QList<int> getExperienceByLevel() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_maxLevel;
  double m_experienceBoost;
  QList<int> m_experienceByLevel;
};

#endif // EVOLUTIVEITEMTYPEDATA_H