#ifndef MODSTERDATA_H
#define MODSTERDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class ModsterData : public AbstractGameData
{
public:
  int getId() const;
  int getSpellIdKroma() const;
  int getItemId() const;
  int getItemIdKroma() const;
  int getModsterId() const;
  int getOrder() const;
  QList<int> getParentsModsterId() const;
  QList<int> getModsterActiveSpells() const;
  QList<int> getModsterPassiveSpells() const;
  QList<int> getModsterHiddenAchievements() const;
  QList<int> getModsterAchievements() const;
  QList<int> getKromaHiddenAchievements() const;
  QList<int> getKromaAchievements() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  int m_spellIdKroma;
  int m_itemId;
  int m_itemIdKroma;
  int m_modsterId;
  int m_order;
  QList<int> m_parentsModsterId;
  QList<int> m_modsterActiveSpells;
  QList<int> m_modsterPassiveSpells;
  QList<int> m_modsterHiddenAchievements;
  QList<int> m_modsterAchievements;
  QList<int> m_kromaHiddenAchievements;
  QList<int> m_kromaAchievements;
};

#endif // MODSTERDATA_H