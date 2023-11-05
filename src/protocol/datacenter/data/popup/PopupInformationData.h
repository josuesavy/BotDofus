#ifndef POPUPINFORMATIONDATA_H
#define POPUPINFORMATIONDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class PopupInformationData : public AbstractGameData
{
public:
  int getId() const;
  uint getParentId() const;
  uint getTitleId() const;
  uint getDescriptionId() const;
  QString getIlluName() const;
  QString getCriterion() const;
  uint getCacheType() const;
  bool getAutoTrigger() const;
  QString getTitle() const;
  QString getDescription() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_parentId;
  uint m_titleId;
  uint m_descriptionId;
  QString m_illuName;
  QString m_criterion;
  uint m_cacheType;
  bool m_autoTrigger;
};

#endif // POPUPINFORMATIONDATA_H