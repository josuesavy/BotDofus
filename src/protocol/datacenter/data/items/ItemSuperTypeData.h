#ifndef ITEMSUPERTYPEDATA_H
#define ITEMSUPERTYPEDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class ItemSuperTypeData : public AbstractGameData
{
public:
  int getId() const;
  QList<int> getPossiblePositions() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  QList<int> m_possiblePositions;
};

#endif // ITEMSUPERTYPEDATA_H