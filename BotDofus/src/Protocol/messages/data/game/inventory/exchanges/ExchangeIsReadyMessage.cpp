#include "ExchangeIsReadyMessage.h"

void ExchangeIsReadyMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeIsReadyMessage(output);
}

void ExchangeIsReadyMessage::serializeAs_ExchangeIsReadyMessage(Writer *output)
{
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeIsReadyMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeDouble(this->id);
  output->writeBool(this->ready);
}

void ExchangeIsReadyMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeIsReadyMessage(input);
}

void ExchangeIsReadyMessage::deserializeAs_ExchangeIsReadyMessage(Reader *input)
{
  this->_idFunc(input);
  this->_readyFunc(input);
}

void ExchangeIsReadyMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeIsReadyMessage(tree);
}

void ExchangeIsReadyMessage::deserializeAsyncAs_ExchangeIsReadyMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeIsReadyMessage::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeIsReadyMessage::_readyFunc, this, std::placeholders::_1));
}

void ExchangeIsReadyMessage::_idFunc(Reader *input)
{
  this->id = input->readDouble();
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeIsReadyMessage -"<<"Forbidden value (" << this->id << ") on element of ExchangeIsReadyMessage.id.";
  }
}

void ExchangeIsReadyMessage::_readyFunc(Reader *input)
{
  this->ready = input->readBool();
}

ExchangeIsReadyMessage::ExchangeIsReadyMessage()
{
  m_type = MessageEnum::EXCHANGEISREADYMESSAGE;
}

