#ifndef RIDEFOODDATA_H
#define RIDEFOODDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"

class RideFoodData : public AbstractGameData
{
public:
  QString getMODULE() const;
  uint getGid() const;
  uint getTypeId() const;
  uint getFamilyId() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  QString m_MODULE;
  uint m_gid;
  uint m_typeId;
  uint m_familyId;
};

#endif // RIDEFOODDATA_H