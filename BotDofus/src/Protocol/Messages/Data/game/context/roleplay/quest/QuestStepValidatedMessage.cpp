#include "QuestStepValidatedMessage.h"

void QuestStepValidatedMessage::serialize(Writer *output)
{
  this->serializeAs_QuestStepValidatedMessage(output);
}

void QuestStepValidatedMessage::serializeAs_QuestStepValidatedMessage(Writer *output)
{
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestStepValidatedMessage -"<<"Forbidden value (" << this->questId << ") on element questId.";
  }
  output->writeVarShort((int)this->questId);
  if(this->stepId < 0)
  {
    qDebug()<<"ERREUR - QuestStepValidatedMessage -"<<"Forbidden value (" << this->stepId << ") on element stepId.";
  }
  output->writeVarShort((int)this->stepId);
}

void QuestStepValidatedMessage::deserialize(Reader *input)
{
  this->deserializeAs_QuestStepValidatedMessage(input);
}

void QuestStepValidatedMessage::deserializeAs_QuestStepValidatedMessage(Reader *input)
{
  this->_questIdFunc(input);
  this->_stepIdFunc(input);
}

void QuestStepValidatedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_QuestStepValidatedMessage(tree);
}

void QuestStepValidatedMessage::deserializeAsyncAs_QuestStepValidatedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&QuestStepValidatedMessage::_questIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&QuestStepValidatedMessage::_stepIdFunc, this, std::placeholders::_1));
}

void QuestStepValidatedMessage::_questIdFunc(Reader *input)
{
  this->questId = input->readVarUhShort();
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestStepValidatedMessage -"<<"Forbidden value (" << this->questId << ") on element of QuestStepValidatedMessage.questId.";
  }
}

void QuestStepValidatedMessage::_stepIdFunc(Reader *input)
{
  this->stepId = input->readVarUhShort();
  if(this->stepId < 0)
  {
    qDebug()<<"ERREUR - QuestStepValidatedMessage -"<<"Forbidden value (" << this->stepId << ") on element of QuestStepValidatedMessage.stepId.";
  }
}

QuestStepValidatedMessage::QuestStepValidatedMessage()
{
  m_type = MessageEnum::QUESTSTEPVALIDATEDMESSAGE;
}

