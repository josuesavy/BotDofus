#ifndef CUSTOMMODEBREEDSPELLDATA_H
#define CUSTOMMODEBREEDSPELLDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class CustomModeBreedSpellData : public AbstractGameData
{
public:
  int getId() const;
  int getPairId() const;
  int getBreedId() const;
  bool getIsInitialSpell() const;
  bool getIsHidden() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  int m_pairId;
  int m_breedId;
  bool m_isInitialSpell;
  bool m_isHidden;
};

#endif // CUSTOMMODEBREEDSPELLDATA_H