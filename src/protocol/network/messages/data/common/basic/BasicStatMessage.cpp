#include "BasicStatMessage.h"

void BasicStatMessage::serialize(Writer *output)
{
  this->serializeAs_BasicStatMessage(output);
}

void BasicStatMessage::serializeAs_BasicStatMessage(Writer *output)
{
  if(this->timeSpent < 0 || this->timeSpent > 9007199254740992)
  {
    qDebug()<<"ERREUR - BasicStatMessage -"<<"Forbidden value (" << this->timeSpent << ") on element timeSpent.";
  }
  output->writeDouble(this->timeSpent);
  output->writeVarShort((int)this->statId);
}

void BasicStatMessage::deserialize(Reader *input)
{
  this->deserializeAs_BasicStatMessage(input);
}

void BasicStatMessage::deserializeAs_BasicStatMessage(Reader *input)
{
  this->_timeSpentFunc(input);
  this->_statIdFunc(input);
}

void BasicStatMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BasicStatMessage(tree);
}

void BasicStatMessage::deserializeAsyncAs_BasicStatMessage(FuncTree tree)
{
  tree.addChild(std::bind(&BasicStatMessage::_timeSpentFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BasicStatMessage::_statIdFunc, this, std::placeholders::_1));
}

void BasicStatMessage::_timeSpentFunc(Reader *input)
{
  this->timeSpent = input->readDouble();
  if(this->timeSpent < 0 || this->timeSpent > 9007199254740992)
  {
    qDebug()<<"ERREUR - BasicStatMessage -"<<"Forbidden value (" << this->timeSpent << ") on element of BasicStatMessage.timeSpent.";
  }
}

void BasicStatMessage::_statIdFunc(Reader *input)
{
  this->statId = input->readVarUhShort();
  if(this->statId < 0)
  {
    qDebug()<<"ERREUR - BasicStatMessage -"<<"Forbidden value (" << this->statId << ") on element of BasicStatMessage.statId.";
  }
}

BasicStatMessage::BasicStatMessage()
{
  m_type = MessageEnum::BASICSTATMESSAGE;
}

