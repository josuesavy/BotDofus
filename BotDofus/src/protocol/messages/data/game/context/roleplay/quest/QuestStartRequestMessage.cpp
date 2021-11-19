#include "QuestStartRequestMessage.h"

void QuestStartRequestMessage::serialize(Writer *output)
{
  this->serializeAs_QuestStartRequestMessage(output);
}

void QuestStartRequestMessage::serializeAs_QuestStartRequestMessage(Writer *output)
{
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestStartRequestMessage -"<<"Forbidden value (" << this->questId << ") on element questId.";
  }
  output->writeVarShort((int)this->questId);
}

void QuestStartRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_QuestStartRequestMessage(input);
}

void QuestStartRequestMessage::deserializeAs_QuestStartRequestMessage(Reader *input)
{
  this->_questIdFunc(input);
}

void QuestStartRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_QuestStartRequestMessage(tree);
}

void QuestStartRequestMessage::deserializeAsyncAs_QuestStartRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&QuestStartRequestMessage::_questIdFunc, this, std::placeholders::_1));
}

void QuestStartRequestMessage::_questIdFunc(Reader *input)
{
  this->questId = input->readVarUhShort();
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestStartRequestMessage -"<<"Forbidden value (" << this->questId << ") on element of QuestStartRequestMessage.questId.";
  }
}

QuestStartRequestMessage::QuestStartRequestMessage()
{
  m_type = MessageEnum::QUESTSTARTREQUESTMESSAGE;
}

