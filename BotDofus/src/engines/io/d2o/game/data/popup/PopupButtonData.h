#ifndef POPUPBUTTONDATA_H
#define POPUPBUTTONDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class PopupButtonData : public AbstractGameData
{
public:
  int getId() const;
  uint getPopupId() const;
  uint getType() const;
  uint getTextId() const;
  uint getActionType() const;
  QString getActionValue() const;
  QString getText() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_popupId;
  uint m_type;
  uint m_textId;
  uint m_actionType;
  QString m_actionValue;
};

#endif // POPUPBUTTONDATA_H