#include "QuestObjectiveValidatedMessage.h"

void QuestObjectiveValidatedMessage::serialize(Writer *output)
{
  this->serializeAs_QuestObjectiveValidatedMessage(output);
}

void QuestObjectiveValidatedMessage::serializeAs_QuestObjectiveValidatedMessage(Writer *output)
{
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestObjectiveValidatedMessage -"<<"Forbidden value (" << this->questId << ") on element questId.";
  }
  output->writeVarShort((int)this->questId);
  if(this->objectiveId < 0)
  {
    qDebug()<<"ERREUR - QuestObjectiveValidatedMessage -"<<"Forbidden value (" << this->objectiveId << ") on element objectiveId.";
  }
  output->writeVarShort((int)this->objectiveId);
}

void QuestObjectiveValidatedMessage::deserialize(Reader *input)
{
  this->deserializeAs_QuestObjectiveValidatedMessage(input);
}

void QuestObjectiveValidatedMessage::deserializeAs_QuestObjectiveValidatedMessage(Reader *input)
{
  this->_questIdFunc(input);
  this->_objectiveIdFunc(input);
}

void QuestObjectiveValidatedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_QuestObjectiveValidatedMessage(tree);
}

void QuestObjectiveValidatedMessage::deserializeAsyncAs_QuestObjectiveValidatedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&QuestObjectiveValidatedMessage::_questIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&QuestObjectiveValidatedMessage::_objectiveIdFunc, this, std::placeholders::_1));
}

void QuestObjectiveValidatedMessage::_questIdFunc(Reader *input)
{
  this->questId = input->readVarUhShort();
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestObjectiveValidatedMessage -"<<"Forbidden value (" << this->questId << ") on element of QuestObjectiveValidatedMessage.questId.";
  }
}

void QuestObjectiveValidatedMessage::_objectiveIdFunc(Reader *input)
{
  this->objectiveId = input->readVarUhShort();
  if(this->objectiveId < 0)
  {
    qDebug()<<"ERREUR - QuestObjectiveValidatedMessage -"<<"Forbidden value (" << this->objectiveId << ") on element of QuestObjectiveValidatedMessage.objectiveId.";
  }
}

QuestObjectiveValidatedMessage::QuestObjectiveValidatedMessage()
{
  m_type = MessageEnum::QUESTOBJECTIVEVALIDATEDMESSAGE;
}

