#ifndef MOUNTFAMILYDATA_H
#define MOUNTFAMILYDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"

class MountFamilyData : public AbstractGameData
{
public:
  uint getId() const;
  uint getNameId() const;
  QString getHeadUri() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_nameId;
  QString m_headUri;
};

#endif // MOUNTFAMILYDATA_H