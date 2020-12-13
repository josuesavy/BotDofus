#ifndef EMBLEMBACKGROUNDDATA_H
#define EMBLEMBACKGROUNDDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"

class EmblemBackgroundData : public AbstractGameData
{
public:
  int getId() const;
  int getOrder() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  int m_order;
};

#endif // EMBLEMBACKGROUNDDATA_H