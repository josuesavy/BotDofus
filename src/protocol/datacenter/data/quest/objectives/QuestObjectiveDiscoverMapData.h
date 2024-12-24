#ifndef QUESTOBJECTIVEDISCOVERMAPDATA_H
#define QUESTOBJECTIVEDISCOVERMAPDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/quest/QuestObjectiveData.h"

class QuestObjectiveDiscoverMapData : public QuestObjectiveData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // QUESTOBJECTIVEDISCOVERMAPDATA_H