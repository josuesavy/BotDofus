#ifndef ITEMCRITERIONOPERATORDATA_H
#define ITEMCRITERIONOPERATORDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"

class ItemCriterionOperatorData : public AbstractGameData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // ITEMCRITERIONOPERATORDATA_H