#include "QuestStepInfoRequestMessage.h"

void QuestStepInfoRequestMessage::serialize(Writer *output)
{
  this->serializeAs_QuestStepInfoRequestMessage(output);
}

void QuestStepInfoRequestMessage::serializeAs_QuestStepInfoRequestMessage(Writer *output)
{
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestStepInfoRequestMessage -"<<"Forbidden value (" << this->questId << ") on element questId.";
  }
  output->writeVarShort((int)this->questId);
}

void QuestStepInfoRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_QuestStepInfoRequestMessage(input);
}

void QuestStepInfoRequestMessage::deserializeAs_QuestStepInfoRequestMessage(Reader *input)
{
  this->_questIdFunc(input);
}

void QuestStepInfoRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_QuestStepInfoRequestMessage(tree);
}

void QuestStepInfoRequestMessage::deserializeAsyncAs_QuestStepInfoRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&QuestStepInfoRequestMessage::_questIdFunc, this, std::placeholders::_1));
}

void QuestStepInfoRequestMessage::_questIdFunc(Reader *input)
{
  this->questId = input->readVarUhShort();
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestStepInfoRequestMessage -"<<"Forbidden value (" << this->questId << ") on element of QuestStepInfoRequestMessage.questId.";
  }
}

QuestStepInfoRequestMessage::QuestStepInfoRequestMessage()
{
  m_type = MessageEnum::QUESTSTEPINFOREQUESTMESSAGE;
}

