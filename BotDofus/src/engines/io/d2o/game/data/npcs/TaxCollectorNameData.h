#ifndef TAXCOLLECTORNAMEDATA_H
#define TAXCOLLECTORNAMEDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"

class TaxCollectorNameData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
};

#endif // TAXCOLLECTORNAMEDATA_H