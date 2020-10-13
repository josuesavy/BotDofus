#include "MountBoneData.h"

uint MountBoneData::getId() const
{
  return m_id;
}

void MountBoneData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
  }
}

