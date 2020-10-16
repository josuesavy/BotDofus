#ifndef MAPCHARACTERSITEMCRITERIONDATA_H
#define MAPCHARACTERSITEMCRITERIONDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/ItemCriterionData.h"

class MapCharactersItemCriterionData : public ItemCriterionData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // MAPCHARACTERSITEMCRITERIONDATA_H