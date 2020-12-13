#ifndef BREACHWORLDMAPSECTORDATA_H
#define BREACHWORLDMAPSECTORDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"

class BreachWorldMapSectorData : public AbstractGameData
{
public:
  uint getId() const;
  uint getSectorNameId() const;
  uint getLegendId() const;
  QString getSectorIcon() const;
  int getMinStage() const;
  int getMaxStage() const;
  QString getLegend() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_sectorNameId;
  uint m_legendId;
  QString m_sectorIcon;
  int m_minStage;
  int m_maxStage;
};

#endif // BREACHWORLDMAPSECTORDATA_H