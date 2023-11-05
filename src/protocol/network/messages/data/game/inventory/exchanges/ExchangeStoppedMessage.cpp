#include "ExchangeStoppedMessage.h"

void ExchangeStoppedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeStoppedMessage(output);
}

void ExchangeStoppedMessage::serializeAs_ExchangeStoppedMessage(Writer *output)
{
  if(this->id < 0 || this->id > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeStoppedMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarLong((double)this->id);
}

void ExchangeStoppedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeStoppedMessage(input);
}

void ExchangeStoppedMessage::deserializeAs_ExchangeStoppedMessage(Reader *input)
{
  this->_idFunc(input);
}

void ExchangeStoppedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeStoppedMessage(tree);
}

void ExchangeStoppedMessage::deserializeAsyncAs_ExchangeStoppedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeStoppedMessage::_idFunc, this, std::placeholders::_1));
}

void ExchangeStoppedMessage::_idFunc(Reader *input)
{
  this->id = input->readVarUhLong();
  if(this->id < 0 || this->id > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeStoppedMessage -"<<"Forbidden value (" << this->id << ") on element of ExchangeStoppedMessage.id.";
  }
}

ExchangeStoppedMessage::ExchangeStoppedMessage()
{
  m_type = MessageEnum::EXCHANGESTOPPEDMESSAGE;
}

