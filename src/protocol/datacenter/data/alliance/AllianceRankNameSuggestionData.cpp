#include "AllianceRankNameSuggestionData.h"

QString AllianceRankNameSuggestionData::getUiKey() const
{
  return m_uiKey;
}

void AllianceRankNameSuggestionData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "uiKey")
        m_uiKey = readUTF(field->getValue());
    
  }
}

