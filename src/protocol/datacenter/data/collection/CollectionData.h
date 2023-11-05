#ifndef COLLECTIONDATA_H
#define COLLECTIONDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class CollectionData : public AbstractGameData
{
public:
  int getTypeId() const;
  int getName() const;
  QString getCriterion() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_typeId;
  int m_name;
  QString m_criterion;
};

#endif // COLLECTIONDATA_H