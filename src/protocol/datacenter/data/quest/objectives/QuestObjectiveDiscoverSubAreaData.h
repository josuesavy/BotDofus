#ifndef QUESTOBJECTIVEDISCOVERSUBAREADATA_H
#define QUESTOBJECTIVEDISCOVERSUBAREADATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/quest/QuestObjectiveData.h"

class QuestObjectiveDiscoverSubAreaData : public QuestObjectiveData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // QUESTOBJECTIVEDISCOVERSUBAREADATA_H