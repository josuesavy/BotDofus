#include "QuestStartedMessage.h"

void QuestStartedMessage::serialize(Writer *output)
{
  this->serializeAs_QuestStartedMessage(output);
}

void QuestStartedMessage::serializeAs_QuestStartedMessage(Writer *output)
{
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestStartedMessage -"<<"Forbidden value (" << this->questId << ") on element questId.";
  }
  output->writeVarShort((int)this->questId);
}

void QuestStartedMessage::deserialize(Reader *input)
{
  this->deserializeAs_QuestStartedMessage(input);
}

void QuestStartedMessage::deserializeAs_QuestStartedMessage(Reader *input)
{
  this->_questIdFunc(input);
}

void QuestStartedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_QuestStartedMessage(tree);
}

void QuestStartedMessage::deserializeAsyncAs_QuestStartedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&QuestStartedMessage::_questIdFunc, this, std::placeholders::_1));
}

void QuestStartedMessage::_questIdFunc(Reader *input)
{
  this->questId = input->readVarUhShort();
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestStartedMessage -"<<"Forbidden value (" << this->questId << ") on element of QuestStartedMessage.questId.";
  }
}

QuestStartedMessage::QuestStartedMessage()
{
  m_type = MessageEnum::QUESTSTARTEDMESSAGE;
}

