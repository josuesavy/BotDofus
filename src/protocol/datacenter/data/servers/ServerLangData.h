#ifndef SERVERLANGDATA_H
#define SERVERLANGDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class ServerLangData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  QString getLangCode() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  QString m_langCode;
};

#endif // SERVERLANGDATA_H