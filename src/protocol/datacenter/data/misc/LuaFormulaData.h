#ifndef LUAFORMULADATA_H
#define LUAFORMULADATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class LuaFormulaData : public AbstractGameData
{
public:
  int getId() const;
  QString getFormulaName() const;
  QString getLuaFormula() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  QString m_formulaName;
  QString m_luaFormula;
};

#endif // LUAFORMULADATA_H