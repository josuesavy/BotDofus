#ifndef AREADATA_H
#define AREADATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class AreaData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getSuperAreaId() const;
  bool getContainHouses() const;
  bool getContainPaddocks() const;
  QRect getBounds() const;
  uint getWorldmapId() const;
  bool getHasWorldMap() const;
  bool getHasSuggestion() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_superAreaId;
  bool m_containHouses;
  bool m_containPaddocks;
  QRect m_bounds;
  uint m_worldmapId;
  bool m_hasWorldMap;
  bool m_hasSuggestion;
};

#endif // AREADATA_H