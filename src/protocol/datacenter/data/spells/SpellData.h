#ifndef SPELLDATA_H
#define SPELLDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/spells/BoundScriptUsageDataData.h"

class SpellData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  uint getDescriptionId() const;
  uint getTypeId() const;
  uint getOrder() const;
  QList<BoundScriptUsageDataData> getBoundScriptUsageData() const;
  QList<BoundScriptUsageDataData> getCriticalHitBoundScriptUsageData() const;
  uint getIconId() const;
  QList<uint> getSpellLevels() const;
  bool getUseParamCache() const;
  bool getVerboseCast() const;
  QString getDefaultPreviewZone() const;
  bool getBypassSummoningLimit() const;
  bool getCanAlwaysTriggerSpells() const;
  QString getAdminName() const;
  bool getHideCastConditions() const;
  QString getName() const;
  QString getDescription() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  uint m_descriptionId;
  uint m_typeId;
  uint m_order;
  QList<BoundScriptUsageDataData> m_boundScriptUsageData;
  QList<BoundScriptUsageDataData> m_criticalHitBoundScriptUsageData;
  uint m_iconId;
  QList<uint> m_spellLevels;
  bool m_useParamCache;
  bool m_verboseCast;
  QString m_defaultPreviewZone;
  bool m_bypassSummoningLimit;
  bool m_canAlwaysTriggerSpells;
  QString m_adminName;
  bool m_hideCastConditions;
};

#endif // SPELLDATA_H