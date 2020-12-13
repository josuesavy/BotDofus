#ifndef SPELLVARIANTDATA_H
#define SPELLVARIANTDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"

class SpellVariantData : public AbstractGameData
{
public:
  int getId() const;
  uint getBreedId() const;
  QList<uint> getSpellIds() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_breedId;
  QList<uint> m_spellIds;
};

#endif // SPELLVARIANTDATA_H