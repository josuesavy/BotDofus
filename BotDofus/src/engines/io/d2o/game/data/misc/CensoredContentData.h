#ifndef CENSOREDCONTENTDATA_H
#define CENSOREDCONTENTDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"

class CensoredContentData : public AbstractGameData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // CENSOREDCONTENTDATA_H