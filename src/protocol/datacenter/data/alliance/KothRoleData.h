#ifndef KOTHROLEDATA_H
#define KOTHROLEDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class KothRoleData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  bool getIsDefault() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  bool m_isDefault;
};

#endif // KOTHROLEDATA_H