#ifndef INTERACTIVEDATA_H
#define INTERACTIVEDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class InteractiveData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getActionId() const;
  bool getDisplayTooltip() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_actionId;
  bool m_displayTooltip;
};

#endif // INTERACTIVEDATA_H