#include "EmblemBackgroundData.h"

int EmblemBackgroundData::getId() const
{
  return m_id;
}

int EmblemBackgroundData::getOrder() const
{
  return m_order;
}

void EmblemBackgroundData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "order")
        m_order = readInt(field->getValue());
    
  }
}

