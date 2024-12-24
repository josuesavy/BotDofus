#ifndef CENSOREDCONTENTDATA_H
#define CENSOREDCONTENTDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class CensoredContentData : public AbstractGameData
{
public:
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);
};

#endif // CENSOREDCONTENTDATA_H