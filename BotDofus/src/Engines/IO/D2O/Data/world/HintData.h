#ifndef HINTDATA_H
#define HINTDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"

class HintData : public AbstractGameData
{
public:
  int getId() const;
  uint getGfx() const;
  uint getNameId() const;
  double getMapId() const;
  double getRealMapId() const;
  int getX() const;
  int getY() const;
  bool getOutdoor() const;
  int getSubareaId() const;
  int getWorldMapId() const;
  uint getLevel() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_gfx;
  uint m_nameId;
  double m_mapId;
  double m_realMapId;
  int m_x;
  int m_y;
  bool m_outdoor;
  int m_subareaId;
  int m_worldMapId;
  uint m_level;
};

#endif // HINTDATA_H