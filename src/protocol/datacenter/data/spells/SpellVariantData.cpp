#include "SpellVariantData.h"

int SpellVariantData::getId() const
{
  return m_id;
}

uint SpellVariantData::getBreedId() const
{
  return m_breedId;
}

QList<uint> SpellVariantData::getSpellIds() const
{
  return m_spellIds;
}

void SpellVariantData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "breedId")
        m_breedId = readUInt(field->getValue());
    
    else if(field->getName() == "spellIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_spellIds << readUInt(data);
    }
    
  }
}

