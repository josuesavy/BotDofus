#ifndef SIGNDATA_H
#define SIGNDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class SignData : public AbstractGameData
{
public:
  int getId() const;
  QString getParams() const;
  int getSkillId() const;
  uint getTextKey() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  QString m_params;
  int m_skillId;
  uint m_textKey;
};

#endif // SIGNDATA_H