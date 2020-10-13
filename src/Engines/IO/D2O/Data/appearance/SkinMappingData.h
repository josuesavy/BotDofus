#ifndef SKINMAPPINGDATA_H
#define SKINMAPPINGDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"

class SkinMappingData : public AbstractGameData
{
public:
  int getId() const;
  int getLowDefId() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  int m_lowDefId;
};

#endif // SKINMAPPINGDATA_H