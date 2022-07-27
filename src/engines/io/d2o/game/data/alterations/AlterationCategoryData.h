#ifndef ALTERATIONCATEGORYDATA_H
#define ALTERATIONCATEGORYDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class AlterationCategoryData : public AbstractGameData
{
public:
  uint getId() const;
  uint getNameId() const;
  uint getParentId() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_nameId;
  uint m_parentId;
};

#endif // ALTERATIONCATEGORYDATA_H