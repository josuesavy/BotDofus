#ifndef FORGETTABLESPELLDATA_H
#define FORGETTABLESPELLDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"

class ForgettableSpellData : public AbstractGameData
{
public:
  int getId() const;
  int getPairId() const;
  int getItemId() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  int m_pairId;
  int m_itemId;
};

#endif // FORGETTABLESPELLDATA_H