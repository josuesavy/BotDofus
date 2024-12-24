#ifndef ACTIVITYSUGGESTIONSCATEGORYDATA_H
#define ACTIVITYSUGGESTIONSCATEGORYDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class ActivitySuggestionsCategoryData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  uint getParentId() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  uint m_parentId;
};

#endif // ACTIVITYSUGGESTIONSCATEGORYDATA_H