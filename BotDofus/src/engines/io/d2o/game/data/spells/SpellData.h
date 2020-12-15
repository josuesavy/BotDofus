#ifndef SPELLDATA_H
#define SPELLDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class SpellData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  uint getDescriptionId() const;
  uint getTypeId() const;
  uint getOrder() const;
  QString getScriptParams() const;
  QString getScriptParamsCritical() const;
  int getScriptId() const;
  int getScriptIdCritical() const;
  uint getIconId() const;
  QList<uint> getSpellLevels() const;
  bool getUseParamCache() const;
  bool getBypassSummoningLimit() const;
  bool getCanAlwaysTriggerSpells() const;
  QString getAdminName() const;
  QString getName() const;
  QString getDescription() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  uint m_descriptionId;
  uint m_typeId;
  uint m_order;
  QString m_scriptParams;
  QString m_scriptParamsCritical;
  int m_scriptId;
  int m_scriptIdCritical;
  uint m_iconId;
  QList<uint> m_spellLevels;
  bool m_useParamCache;
  bool m_bypassSummoningLimit;
  bool m_canAlwaysTriggerSpells;
  QString m_adminName;
};

#endif // SPELLDATA_H