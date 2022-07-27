#ifndef CHARACTERISTICDATA_H
#define CHARACTERISTICDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class CharacteristicData : public AbstractGameData
{
public:
  int getId() const;
  QString getKeyword() const;
  uint getNameId() const;
  QString getAsset() const;
  int getCategoryId() const;
  bool getVisible() const;
  int getOrder() const;
  int getScaleFormulaId() const;
  bool getUpgradable() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  QString m_keyword;
  uint m_nameId;
  QString m_asset;
  int m_categoryId;
  bool m_visible;
  int m_order;
  int m_scaleFormulaId;
  bool m_upgradable;
};

#endif // CHARACTERISTICDATA_H