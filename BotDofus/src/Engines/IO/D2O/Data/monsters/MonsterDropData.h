#ifndef MONSTERDROPDATA_H
#define MONSTERDROPDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"
#include "src/Engines/IO/D2O/Data/monsters/MonsterDropCoefficientData.h"

class MonsterDropData : public AbstractGameData
{
public:
  uint getDropId() const;
  int getMonsterId() const;
  int getObjectId() const;
  double getPercentDropForGrade1() const;
  double getPercentDropForGrade2() const;
  double getPercentDropForGrade3() const;
  double getPercentDropForGrade4() const;
  double getPercentDropForGrade5() const;
  int getCount() const;
  QString getCriteria() const;
  bool getHasCriteria() const;
  QList<MonsterDropCoefficientData> getSpecificDropCoefficient() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_dropId;
  int m_monsterId;
  int m_objectId;
  double m_percentDropForGrade1;
  double m_percentDropForGrade2;
  double m_percentDropForGrade3;
  double m_percentDropForGrade4;
  double m_percentDropForGrade5;
  int m_count;
  QString m_criteria;
  bool m_hasCriteria;
  QList<MonsterDropCoefficientData> m_specificDropCoefficient;
};

#endif // MONSTERDROPDATA_H