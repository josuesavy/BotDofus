#ifndef TITLECATEGORYDATA_H
#define TITLECATEGORYDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class TitleCategoryData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
};

#endif // TITLECATEGORYDATA_H