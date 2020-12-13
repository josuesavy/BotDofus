#ifndef ALIGNMENTGIFTDATA_H
#define ALIGNMENTGIFTDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"

class AlignmentGiftData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getEffectId() const;
  uint getGfxId() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_effectId;
  uint m_gfxId;
};

#endif // ALIGNMENTGIFTDATA_H