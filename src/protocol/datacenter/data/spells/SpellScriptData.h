#ifndef SPELLSCRIPTDATA_H
#define SPELLSCRIPTDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class SpellScriptData : public AbstractGameData
{
public:
  int getId() const;
  int getTypeId() const;
  QString getRawParams() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  int m_typeId;
  QString m_rawParams;
};

#endif // SPELLSCRIPTDATA_H