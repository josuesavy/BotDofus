#ifndef CREATUREBONEOVERRIDEDATA_H
#define CREATUREBONEOVERRIDEDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class CreatureBoneOverrideData : public AbstractGameData
{
public:
  int getBoneId() const;
  int getCreatureBoneId() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_boneId;
  int m_creatureBoneId;
};

#endif // CREATUREBONEOVERRIDEDATA_H