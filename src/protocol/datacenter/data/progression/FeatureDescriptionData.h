#ifndef FEATUREDESCRIPTIONDATA_H
#define FEATUREDESCRIPTIONDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class FeatureDescriptionData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  uint getDescriptionId() const;
  uint getPriority() const;
  uint getParentId() const;
  QList<int> getChildren() const;
  QString getCriterion() const;
  QString getName() const;
  QString getDescription() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  uint m_descriptionId;
  uint m_priority;
  uint m_parentId;
  QList<int> m_children;
  QString m_criterion;
};

#endif // FEATUREDESCRIPTIONDATA_H