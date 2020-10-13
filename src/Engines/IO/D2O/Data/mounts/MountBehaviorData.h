#ifndef MOUNTBEHAVIORDATA_H
#define MOUNTBEHAVIORDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"

class MountBehaviorData : public AbstractGameData
{
public:
  uint getId() const;
  uint getNameId() const;
  uint getDescriptionId() const;
  QString getName() const;
  QString getDescription() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_nameId;
  uint m_descriptionId;
};

#endif // MOUNTBEHAVIORDATA_H