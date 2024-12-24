#ifndef SOCIALTAGSTYPEDATA_H
#define SOCIALTAGSTYPEDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class SocialTagsTypeData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
};

#endif // SOCIALTAGSTYPEDATA_H