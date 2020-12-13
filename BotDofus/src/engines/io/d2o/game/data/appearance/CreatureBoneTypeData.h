#ifndef CREATUREBONETYPEDATA_H
#define CREATUREBONETYPEDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"

class CreatureBoneTypeData : public AbstractGameData
{
public:
  int getId() const;
  int getCreatureBoneId() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  int m_creatureBoneId;
};

#endif // CREATUREBONETYPEDATA_H