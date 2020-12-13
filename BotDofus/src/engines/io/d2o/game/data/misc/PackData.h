#ifndef PACKDATA_H
#define PACKDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"

class PackData : public AbstractGameData
{
public:
  int getId() const;
  QString getName() const;
  bool getHasSubAreas() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  QString m_name;
  bool m_hasSubAreas;
};

#endif // PACKDATA_H