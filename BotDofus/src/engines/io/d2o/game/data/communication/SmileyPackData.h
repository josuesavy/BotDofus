#ifndef SMILEYPACKDATA_H
#define SMILEYPACKDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class SmileyPackData : public AbstractGameData
{
public:
  uint getId() const;
  uint getNameId() const;
  uint getOrder() const;
  QList<uint> getSmileys() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_nameId;
  uint m_order;
  QList<uint> m_smileys;
};

#endif // SMILEYPACKDATA_H