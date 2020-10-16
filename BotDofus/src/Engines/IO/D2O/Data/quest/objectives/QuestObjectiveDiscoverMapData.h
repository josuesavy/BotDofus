#ifndef QUESTOBJECTIVEDISCOVERMAPDATA_H
#define QUESTOBJECTIVEDISCOVERMAPDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"
#include "src/Engines/IO/D2O/Data/quest/QuestObjectiveData.h"

class QuestObjectiveDiscoverMapData : public QuestObjectiveData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // QUESTOBJECTIVEDISCOVERMAPDATA_H