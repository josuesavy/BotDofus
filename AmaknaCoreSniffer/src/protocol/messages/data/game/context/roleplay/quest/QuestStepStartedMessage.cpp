#include "QuestStepStartedMessage.h"

void QuestStepStartedMessage::serialize(Writer *output)
{
  this->serializeAs_QuestStepStartedMessage(output);
}

void QuestStepStartedMessage::serializeAs_QuestStepStartedMessage(Writer *output)
{
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestStepStartedMessage -"<<"Forbidden value (" << this->questId << ") on element questId.";
  }
  output->writeVarShort((int)this->questId);
  if(this->stepId < 0)
  {
    qDebug()<<"ERREUR - QuestStepStartedMessage -"<<"Forbidden value (" << this->stepId << ") on element stepId.";
  }
  output->writeVarShort((int)this->stepId);
}

void QuestStepStartedMessage::deserialize(Reader *input)
{
  this->deserializeAs_QuestStepStartedMessage(input);
}

void QuestStepStartedMessage::deserializeAs_QuestStepStartedMessage(Reader *input)
{
  this->_questIdFunc(input);
  this->_stepIdFunc(input);
}

void QuestStepStartedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_QuestStepStartedMessage(tree);
}

void QuestStepStartedMessage::deserializeAsyncAs_QuestStepStartedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&QuestStepStartedMessage::_questIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&QuestStepStartedMessage::_stepIdFunc, this, std::placeholders::_1));
}

void QuestStepStartedMessage::_questIdFunc(Reader *input)
{
  this->questId = input->readVarUhShort();
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestStepStartedMessage -"<<"Forbidden value (" << this->questId << ") on element of QuestStepStartedMessage.questId.";
  }
}

void QuestStepStartedMessage::_stepIdFunc(Reader *input)
{
  this->stepId = input->readVarUhShort();
  if(this->stepId < 0)
  {
    qDebug()<<"ERREUR - QuestStepStartedMessage -"<<"Forbidden value (" << this->stepId << ") on element of QuestStepStartedMessage.stepId.";
  }
}

QuestStepStartedMessage::QuestStepStartedMessage()
{
  m_type = MessageEnum::QUESTSTEPSTARTEDMESSAGE;
}

