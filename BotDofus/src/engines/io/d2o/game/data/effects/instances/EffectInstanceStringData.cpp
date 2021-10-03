#include "EffectInstanceStringData.h"

QString EffectInstanceStringData::getText() const
{
  return m_text;
}

void EffectInstanceStringData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  EffectInstanceData::loadData(fields, I18n);
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "text")
        m_text = readUTF(field->getValue());
    
  }
}

