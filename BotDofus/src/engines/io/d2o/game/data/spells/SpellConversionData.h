#ifndef SPELLCONVERSIONDATA_H
#define SPELLCONVERSIONDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class SpellConversionData : public AbstractGameData
{
public:
  uint getOldSpellId() const;
  uint getNewSpellId() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_oldSpellId;
  uint m_newSpellId;
};

#endif // SPELLCONVERSIONDATA_H