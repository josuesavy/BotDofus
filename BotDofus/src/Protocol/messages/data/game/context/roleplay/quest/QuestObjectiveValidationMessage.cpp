#include "QuestObjectiveValidationMessage.h"

void QuestObjectiveValidationMessage::serialize(Writer *output)
{
  this->serializeAs_QuestObjectiveValidationMessage(output);
}

void QuestObjectiveValidationMessage::serializeAs_QuestObjectiveValidationMessage(Writer *output)
{
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestObjectiveValidationMessage -"<<"Forbidden value (" << this->questId << ") on element questId.";
  }
  output->writeVarShort((int)this->questId);
  if(this->objectiveId < 0)
  {
    qDebug()<<"ERREUR - QuestObjectiveValidationMessage -"<<"Forbidden value (" << this->objectiveId << ") on element objectiveId.";
  }
  output->writeVarShort((int)this->objectiveId);
}

void QuestObjectiveValidationMessage::deserialize(Reader *input)
{
  this->deserializeAs_QuestObjectiveValidationMessage(input);
}

void QuestObjectiveValidationMessage::deserializeAs_QuestObjectiveValidationMessage(Reader *input)
{
  this->_questIdFunc(input);
  this->_objectiveIdFunc(input);
}

void QuestObjectiveValidationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_QuestObjectiveValidationMessage(tree);
}

void QuestObjectiveValidationMessage::deserializeAsyncAs_QuestObjectiveValidationMessage(FuncTree tree)
{
  tree.addChild(std::bind(&QuestObjectiveValidationMessage::_questIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&QuestObjectiveValidationMessage::_objectiveIdFunc, this, std::placeholders::_1));
}

void QuestObjectiveValidationMessage::_questIdFunc(Reader *input)
{
  this->questId = input->readVarUhShort();
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestObjectiveValidationMessage -"<<"Forbidden value (" << this->questId << ") on element of QuestObjectiveValidationMessage.questId.";
  }
}

void QuestObjectiveValidationMessage::_objectiveIdFunc(Reader *input)
{
  this->objectiveId = input->readVarUhShort();
  if(this->objectiveId < 0)
  {
    qDebug()<<"ERREUR - QuestObjectiveValidationMessage -"<<"Forbidden value (" << this->objectiveId << ") on element of QuestObjectiveValidationMessage.objectiveId.";
  }
}

QuestObjectiveValidationMessage::QuestObjectiveValidationMessage()
{
  m_type = MessageEnum::QUESTOBJECTIVEVALIDATIONMESSAGE;
}

