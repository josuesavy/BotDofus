#include "PopupButtonData.h"

int PopupButtonData::getId() const
{
  return m_id;
}

uint PopupButtonData::getPopupId() const
{
  return m_popupId;
}

uint PopupButtonData::getType() const
{
  return m_type;
}

uint PopupButtonData::getTextId() const
{
  return m_textId;
}

uint PopupButtonData::getActionType() const
{
  return m_actionType;
}

QString PopupButtonData::getActionValue() const
{
  return m_actionValue;
}

QString PopupButtonData::getText() const
{
  return m_I18n->getText(m_textId);
}

void PopupButtonData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "popupId")
        m_popupId = readUInt(field->getValue());
    
    else if(field->getName() == "type")
        m_type = readUInt(field->getValue());
    
    else if(field->getName() == "textId")
        m_textId = readUInt(field->getValue());
    
    else if(field->getName() == "actionType")
        m_actionType = readUInt(field->getValue());
    
    else if(field->getName() == "actionValue")
        m_actionValue = readUTF(field->getValue());
    
  }
}

