#ifndef COLLECTIONDATA_H
#define COLLECTIONDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/collection/CollectableData.h"

class CollectionData : public AbstractGameData
{
public:
  int getTypeId() const;
  int getName() const;
  QString getCriterion() const;
  QList<CollectableData> getCollectables() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_typeId;
  int m_name;
  QString m_criterion;
  QList<CollectableData> m_collectables;
};

#endif // COLLECTIONDATA_H