#include "AllianceTagData.h"

void AllianceTagData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  SocialTagData::loadData(fields, I18n);
  
  foreach (D2OField *field, fields)
  {
  }
}

