#ifndef MONSTERDROPCOEFFICIENTDATA_H
#define MONSTERDROPCOEFFICIENTDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class MonsterDropCoefficientData : public AbstractGameData
{
public:
  uint getMonsterId() const;
  uint getMonsterGrade() const;
  double getDropCoefficient() const;
  QString getCriteria() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_monsterId;
  uint m_monsterGrade;
  double m_dropCoefficient;
  QString m_criteria;
};

#endif // MONSTERDROPCOEFFICIENTDATA_H