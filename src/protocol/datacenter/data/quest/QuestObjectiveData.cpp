#include "QuestObjectiveData.h"

uint QuestObjectiveData::getId() const
{
  return m_id;
}

uint QuestObjectiveData::getStepId() const
{
  return m_stepId;
}

uint QuestObjectiveData::getTypeId() const
{
  return m_typeId;
}

int QuestObjectiveData::getDialogId() const
{
  return m_dialogId;
}

QPoint QuestObjectiveData::getCoords() const
{
  return m_coords;
}

double QuestObjectiveData::getMapId() const
{
  return m_mapId;
}

QString QuestObjectiveData::getDialog() const
{
  return m_I18n->getText(m_dialogId);
}

void QuestObjectiveData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "stepId")
        m_stepId = readUInt(field->getValue());
    
    else if(field->getName() == "typeId")
        m_typeId = readUInt(field->getValue());
    
    else if(field->getName() == "dialogId")
        m_dialogId = readInt(field->getValue());
    
    else if(field->getName() == "coords")
        m_coords = readPoint(field->getValue());
    
    else if(field->getName() == "mapId")
        m_mapId = readDouble(field->getValue());
    
  }
}

