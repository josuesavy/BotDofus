#ifndef MODSTERDATA_H
#define MODSTERDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class ModsterData : public AbstractGameData
{
public:
  int getId() const;
  int getItemId() const;
  int getModsterId() const;
  int getOrder() const;
  QList<int> getParentsModsterId() const;
  QList<int> getModsterActiveSpells() const;
  QList<int> getModsterPassiveSpells() const;
  QList<int> getModsterHiddenAchievements() const;
  QList<int> getModsterAchievements() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  int m_itemId;
  int m_modsterId;
  int m_order;
  QList<int> m_parentsModsterId;
  QList<int> m_modsterActiveSpells;
  QList<int> m_modsterPassiveSpells;
  QList<int> m_modsterHiddenAchievements;
  QList<int> m_modsterAchievements;
};

#endif // MODSTERDATA_H