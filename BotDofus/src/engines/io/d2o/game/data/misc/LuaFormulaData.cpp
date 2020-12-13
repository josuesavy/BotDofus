#include "LuaFormulaData.h"

int LuaFormulaData::getId() const
{
  return m_id;
}

QString LuaFormulaData::getFormulaName() const
{
  return m_formulaName;
}

QString LuaFormulaData::getLuaFormula() const
{
  return m_luaFormula;
}

void LuaFormulaData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "formulaName")
        m_formulaName = readUTF(field->getValue());
    
    else if(field->getName() == "luaFormula")
        m_luaFormula = readUTF(field->getValue());
    
  }
}

