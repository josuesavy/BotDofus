#ifndef EFFECTINSTANCEDATA_H
#define EFFECTINSTANCEDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class EffectInstanceData : public AbstractGameData
{
public:
  uint getEffectUid() const;
  uint getBaseEffectId() const;
  uint getEffectId() const;
  int getOrder() const;
  int getTargetId() const;
  QString getTargetMask() const;
  int getDuration() const;
  int getDelay() const;
  double getRandom() const;
  int getGroup() const;
  int getModificator() const;
  bool getTrigger() const;
  QString getTriggers() const;
  bool getVisibleInTooltip() const;
  bool getVisibleInBuffUi() const;
  bool getVisibleInFightLog() const;
  bool getVisibleOnTerrain() const;
  bool getForClientOnly() const;
  int getDispellable() const;
  uint getZoneShape() const;
  int getEffectElement() const;
  int getSpellId() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_effectUid;
  uint m_baseEffectId;
  uint m_effectId;
  int m_order;
  int m_targetId;
  QString m_targetMask;
  int m_duration;
  int m_delay;
  double m_random;
  int m_group;
  int m_modificator;
  bool m_trigger;
  QString m_triggers;
  bool m_visibleInTooltip;
  bool m_visibleInBuffUi;
  bool m_visibleInFightLog;
  bool m_visibleOnTerrain;
  bool m_forClientOnly;
  int m_dispellable;
  uint m_zoneShape;
  int m_effectElement;
  int m_spellId;
};

#endif // EFFECTINSTANCEDATA_H