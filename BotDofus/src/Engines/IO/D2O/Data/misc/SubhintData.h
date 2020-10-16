#ifndef SUBHINTDATA_H
#define SUBHINTDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"

class SubhintData : public AbstractGameData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // SUBHINTDATA_H