#ifndef LEGENDARYPOWERCATEGORYDATA_H
#define LEGENDARYPOWERCATEGORYDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"

class LegendaryPowerCategoryData : public AbstractGameData
{
public:
  int getId() const;
  QString getCategoryName() const;
  bool getCategoryOverridable() const;
  QList<int> getCategorySpells() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  QString m_categoryName;
  bool m_categoryOverridable;
  QList<int> m_categorySpells;
};

#endif // LEGENDARYPOWERCATEGORYDATA_H