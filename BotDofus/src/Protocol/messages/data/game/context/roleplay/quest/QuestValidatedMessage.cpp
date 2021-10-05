#include "QuestValidatedMessage.h"

void QuestValidatedMessage::serialize(Writer *output)
{
  this->serializeAs_QuestValidatedMessage(output);
}

void QuestValidatedMessage::serializeAs_QuestValidatedMessage(Writer *output)
{
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestValidatedMessage -"<<"Forbidden value (" << this->questId << ") on element questId.";
  }
  output->writeVarShort((int)this->questId);
}

void QuestValidatedMessage::deserialize(Reader *input)
{
  this->deserializeAs_QuestValidatedMessage(input);
}

void QuestValidatedMessage::deserializeAs_QuestValidatedMessage(Reader *input)
{
  this->_questIdFunc(input);
}

void QuestValidatedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_QuestValidatedMessage(tree);
}

void QuestValidatedMessage::deserializeAsyncAs_QuestValidatedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&QuestValidatedMessage::_questIdFunc, this, std::placeholders::_1));
}

void QuestValidatedMessage::_questIdFunc(Reader *input)
{
  this->questId = input->readVarUhShort();
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestValidatedMessage -"<<"Forbidden value (" << this->questId << ") on element of QuestValidatedMessage.questId.";
  }
}

QuestValidatedMessage::QuestValidatedMessage()
{
  m_type = MessageEnum::QUESTVALIDATEDMESSAGE;
}

