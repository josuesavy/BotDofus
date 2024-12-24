#include "InfoMessageData.h"

uint InfoMessageData::getTypeId() const
{
  return m_typeId;
}

uint InfoMessageData::getMessageId() const
{
  return m_messageId;
}

uint InfoMessageData::getTextId() const
{
  return m_textId;
}

QString InfoMessageData::getText() const
{
  return m_I18n->getText(m_textId);
}

void InfoMessageData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "typeId")
        m_typeId = readUInt(field->getValue());
    
    else if(field->getName() == "messageId")
        m_messageId = readUInt(field->getValue());
    
    else if(field->getName() == "textId")
        m_textId = readUInt(field->getValue());
    
  }
}

