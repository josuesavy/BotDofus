#ifndef SERVERPOPULATIONDATA_H
#define SERVERPOPULATIONDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class ServerPopulationData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getWeight() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_weight;
};

#endif // SERVERPOPULATIONDATA_H