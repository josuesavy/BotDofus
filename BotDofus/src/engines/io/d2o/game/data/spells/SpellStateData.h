#ifndef SPELLSTATEDATA_H
#define SPELLSTATEDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"

class SpellStateData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  bool getPreventsSpellCast() const;
  bool getPreventsFight() const;
  bool getIsSilent() const;
  bool getCantDealDamage() const;
  bool getInvulnerable() const;
  bool getIncurable() const;
  bool getCantBeMoved() const;
  bool getCantBePushed() const;
  bool getCantSwitchPosition() const;
  QList<int> getEffectsIds() const;
  QString getIcon() const;
  int getIconVisibilityMask() const;
  bool getInvulnerableMelee() const;
  bool getInvulnerableRange() const;
  bool getCantTackle() const;
  bool getCantBeTackled() const;
  bool getDisplayTurnRemaining() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  bool m_preventsSpellCast;
  bool m_preventsFight;
  bool m_isSilent;
  bool m_cantDealDamage;
  bool m_invulnerable;
  bool m_incurable;
  bool m_cantBeMoved;
  bool m_cantBePushed;
  bool m_cantSwitchPosition;
  QList<int> m_effectsIds;
  QString m_icon;
  int m_iconVisibilityMask;
  bool m_invulnerableMelee;
  bool m_invulnerableRange;
  bool m_cantTackle;
  bool m_cantBeTackled;
  bool m_displayTurnRemaining;
};

#endif // SPELLSTATEDATA_H