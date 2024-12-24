#ifndef ALIGNMENTSIDEDATA_H
#define ALIGNMENTSIDEDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class AlignmentSideData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
};

#endif // ALIGNMENTSIDEDATA_H