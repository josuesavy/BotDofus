#include "PointOfInterestCategoryData.h"

uint PointOfInterestCategoryData::getId() const
{
  return m_id;
}

uint PointOfInterestCategoryData::getActionLabelId() const
{
  return m_actionLabelId;
}

QString PointOfInterestCategoryData::getActionLabel() const
{
  return m_I18n->getText(m_actionLabelId);
}

void PointOfInterestCategoryData::loadData(const QList<D2OField*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (D2OField *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "actionLabelId")
        m_actionLabelId = readUInt(field->getValue());
    
  }
}

