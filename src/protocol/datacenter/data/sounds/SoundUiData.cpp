#include "SoundUiData.h"

QString SoundUiData::getMODULE() const
{
  return m_MODULE;
}

uint SoundUiData::getId() const
{
  return m_id;
}

QString SoundUiData::getUiName() const
{
  return m_uiName;
}

QString SoundUiData::getOpenFile() const
{
  return m_openFile;
}

QString SoundUiData::getCloseFile() const
{
  return m_closeFile;
}

void SoundUiData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "MODULE")
        m_MODULE = readUTF(field->getValue());
    
    else if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "uiName")
        m_uiName = readUTF(field->getValue());
    
    else if(field->getName() == "openFile")
        m_openFile = readUTF(field->getValue());
    
    else if(field->getName() == "closeFile")
        m_closeFile = readUTF(field->getValue());
    
  }
}

