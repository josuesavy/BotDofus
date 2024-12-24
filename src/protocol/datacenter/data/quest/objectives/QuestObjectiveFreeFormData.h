#ifndef QUESTOBJECTIVEFREEFORMDATA_H
#define QUESTOBJECTIVEFREEFORMDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/quest/QuestObjectiveData.h"

class QuestObjectiveFreeFormData : public QuestObjectiveData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // QUESTOBJECTIVEFREEFORMDATA_H