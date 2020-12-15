#ifndef ALIGNMENTSIDEDATA_H
#define ALIGNMENTSIDEDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class AlignmentSideData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  bool getCanConquest() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  bool m_canConquest;
};

#endif // ALIGNMENTSIDEDATA_H