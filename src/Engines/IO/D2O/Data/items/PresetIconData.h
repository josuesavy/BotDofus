#ifndef PRESETICONDATA_H
#define PRESETICONDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"

class PresetIconData : public AbstractGameData
{
public:
  int getId() const;
  int getOrder() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  int m_order;
};

#endif // PRESETICONDATA_H