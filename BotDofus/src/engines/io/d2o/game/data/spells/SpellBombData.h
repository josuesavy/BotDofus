#ifndef SPELLBOMBDATA_H
#define SPELLBOMBDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class SpellBombData : public AbstractGameData
{
public:
  int getId() const;
  int getChainReactionSpellId() const;
  int getExplodSpellId() const;
  int getWallId() const;
  int getInstantSpellId() const;
  int getComboCoeff() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  int m_chainReactionSpellId;
  int m_explodSpellId;
  int m_wallId;
  int m_instantSpellId;
  int m_comboCoeff;
};

#endif // SPELLBOMBDATA_H