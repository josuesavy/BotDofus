#ifndef ORNAMENTDATA_H
#define ORNAMENTDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"

class OrnamentData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  bool getVisible() const;
  int getAssetId() const;
  int getIconId() const;
  int getRarity() const;
  int getOrder() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  bool m_visible;
  int m_assetId;
  int m_iconId;
  int m_rarity;
  int m_order;
};

#endif // ORNAMENTDATA_H