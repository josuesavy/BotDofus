#ifndef RANDOMDROPGROUPDATA_H
#define RANDOMDROPGROUPDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"
#include "src/engines/io/d2o/game/data/items/RandomDropItemData.h"

class RandomDropGroupData : public AbstractGameData
{
public:
  uint getId() const;
  QString getName() const;
  QString getDescription() const;
  QList<RandomDropItemData> getRandomDropItems() const;
  bool getDisplayChances() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  QString m_name;
  QString m_description;
  QList<RandomDropItemData> m_randomDropItems;
  bool m_displayChances;
};

#endif // RANDOMDROPGROUPDATA_H