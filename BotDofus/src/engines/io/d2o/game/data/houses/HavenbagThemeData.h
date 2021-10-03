#ifndef HAVENBAGTHEMEDATA_H
#define HAVENBAGTHEMEDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class HavenbagThemeData : public AbstractGameData
{
public:
  int getId() const;
  int getNameId() const;
  double getMapId() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  int m_nameId;
  double m_mapId;
};

#endif // HAVENBAGTHEMEDATA_H