#ifndef NAMINGRULEDATA_H
#define NAMINGRULEDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"

class NamingRuleData : public AbstractGameData
{
public:
  uint getId() const;
  uint getMinLength() const;
  uint getMaxLength() const;
  QString getRegexp() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_minLength;
  uint m_maxLength;
  QString m_regexp;
};

#endif // NAMINGRULEDATA_H