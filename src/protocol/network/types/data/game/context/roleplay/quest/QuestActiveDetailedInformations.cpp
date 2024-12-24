#include "QuestActiveDetailedInformations.h"

void QuestActiveDetailedInformations::serialize(Writer *output)
{
  this->serializeAs_QuestActiveDetailedInformations(output);
}

void QuestActiveDetailedInformations::serializeAs_QuestActiveDetailedInformations(Writer *output)
{
  QuestActiveInformations::serializeAs_QuestActiveInformations(output);
  if(this->stepId < 0)
  {
    qDebug()<<"ERREUR - QuestActiveDetailedInformations -"<<"Forbidden value (" << this->stepId << ") on element stepId.";
  }
  output->writeVarShort((int)this->stepId);
  output->writeShort((short)this->objectives.size());
  for(uint _i2 = 0; _i2 < this->objectives.size(); _i2++)
  {
    output->writeShort((short)qSharedPointerCast<QuestObjectiveInformations>(this->objectives[_i2])->getTypes().last());
    qSharedPointerCast<QuestObjectiveInformations>(this->objectives[_i2])->serialize(output);
  }
}

void QuestActiveDetailedInformations::deserialize(Reader *input)
{
  this->deserializeAs_QuestActiveDetailedInformations(input);
}

void QuestActiveDetailedInformations::deserializeAs_QuestActiveDetailedInformations(Reader *input)
{
  uint _id2 = 0;
  QSharedPointer<QuestObjectiveInformations> _item2 ;
  QuestActiveInformations::deserialize(input);
  this->_stepIdFunc(input);
  uint _objectivesLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _objectivesLen; _i2++)
  {
    _id2 = uint(input->readUShort());
    _item2 = qSharedPointerCast<QuestObjectiveInformations>(ClassManagerSingleton::get()->getClass(_id2));
    _item2->deserialize(input);
    this->objectives.append(_item2);
  }
}

void QuestActiveDetailedInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_QuestActiveDetailedInformations(tree);
}

void QuestActiveDetailedInformations::deserializeAsyncAs_QuestActiveDetailedInformations(FuncTree tree)
{
  QuestActiveInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&QuestActiveDetailedInformations::_stepIdFunc, this, std::placeholders::_1));
  this->_objectivestree = tree.addChild(std::bind(&QuestActiveDetailedInformations::_objectivestreeFunc, this, std::placeholders::_1));
}

void QuestActiveDetailedInformations::_stepIdFunc(Reader *input)
{
  this->stepId = input->readVarUhShort();
  if(this->stepId < 0)
  {
    qDebug()<<"ERREUR - QuestActiveDetailedInformations -"<<"Forbidden value (" << this->stepId << ") on element of QuestActiveDetailedInformations.stepId.";
  }
}

void QuestActiveDetailedInformations::_objectivestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_objectivestree.addChild(std::bind(&QuestActiveDetailedInformations::_objectivesFunc, this, std::placeholders::_1));
  }
}

void QuestActiveDetailedInformations::_objectivesFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<QuestObjectiveInformations> _item = qSharedPointerCast<QuestObjectiveInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->objectives.append(_item);
}

QuestActiveDetailedInformations::QuestActiveDetailedInformations()
{
  m_types<<ClassEnum::QUESTACTIVEDETAILEDINFORMATIONS;
}

bool QuestActiveDetailedInformations::operator==(const QuestActiveDetailedInformations &compared)
{
  if(stepId == compared.stepId)
  if(objectives == compared.objectives)
  if(_objectivestree == compared._objectivestree)
  return true;
  
  return false;
}

