#ifndef QUESTOBJECTIVEFIGHTMONSTERSONMAPDATA_H
#define QUESTOBJECTIVEFIGHTMONSTERSONMAPDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/quest/QuestObjectiveData.h"

class QuestObjectiveFightMonstersOnMapData : public QuestObjectiveData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // QUESTOBJECTIVEFIGHTMONSTERSONMAPDATA_H