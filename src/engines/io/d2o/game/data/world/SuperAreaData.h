#ifndef SUPERAREADATA_H
#define SUPERAREADATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class SuperAreaData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  uint getWorldmapId() const;
  bool getHasWorldMap() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  uint m_worldmapId;
  bool m_hasWorldMap;
};

#endif // SUPERAREADATA_H