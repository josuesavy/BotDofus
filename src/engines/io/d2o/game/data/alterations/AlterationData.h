#ifndef ALTERATIONDATA_H
#define ALTERATIONDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/effects/EffectInstanceData.h"

class AlterationData : public AbstractGameData
{
public:
  uint getId() const;
  uint getNameId() const;
  uint getDescriptionId() const;
  uint getCategoryId() const;
  uint getIconId() const;
  bool getIsVisible() const;
  QString getCriteria() const;
  bool getIsWebDisplay() const;
  QList<EffectInstanceData> getPossibleEffects() const;
  QString getName() const;
  QString getDescription() const;
  QString getCategory() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_nameId;
  uint m_descriptionId;
  uint m_categoryId;
  uint m_iconId;
  bool m_isVisible;
  QString m_criteria;
  bool m_isWebDisplay;
  QList<EffectInstanceData> m_possibleEffects;
};

#endif // ALTERATIONDATA_H