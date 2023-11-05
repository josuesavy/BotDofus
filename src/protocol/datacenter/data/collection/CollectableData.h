#ifndef COLLECTABLEDATA_H
#define COLLECTABLEDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class CollectableData : public AbstractGameData
{
public:
  int getEntityId() const;
  int getName() const;
  int getTypeId() const;
  int getGfxId() const;
  int getOrder() const;
  int getRarity() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_entityId;
  int m_name;
  int m_typeId;
  int m_gfxId;
  int m_order;
  int m_rarity;
};

#endif // COLLECTABLEDATA_H