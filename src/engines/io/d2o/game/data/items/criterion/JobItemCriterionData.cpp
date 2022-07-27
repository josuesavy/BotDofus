#include "JobItemCriterionData.h"

void JobItemCriterionData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  ItemCriterionData::loadData(fields, I18n);
  
  foreach (D2OField *field, fields)
  {
  }
}

