#ifndef MAPSCROLLACTIONDATA_H
#define MAPSCROLLACTIONDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"

class MapScrollActionData : public AbstractGameData
{
public:
  double getId() const;
  bool getRightExists() const;
  bool getBottomExists() const;
  bool getLeftExists() const;
  bool getTopExists() const;
  double getRightMapId() const;
  double getBottomMapId() const;
  double getLeftMapId() const;
  double getTopMapId() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  double m_id;
  bool m_rightExists;
  bool m_bottomExists;
  bool m_leftExists;
  bool m_topExists;
  double m_rightMapId;
  double m_bottomMapId;
  double m_leftMapId;
  double m_topMapId;
};

#endif // MAPSCROLLACTIONDATA_H