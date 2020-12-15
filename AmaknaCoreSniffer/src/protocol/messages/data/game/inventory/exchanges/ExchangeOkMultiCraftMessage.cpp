#include "ExchangeOkMultiCraftMessage.h"

void ExchangeOkMultiCraftMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeOkMultiCraftMessage(output);
}

void ExchangeOkMultiCraftMessage::serializeAs_ExchangeOkMultiCraftMessage(Writer *output)
{
  if(this->initiatorId < 0 || this->initiatorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeOkMultiCraftMessage -"<<"Forbidden value (" << this->initiatorId << ") on element initiatorId.";
  }
  output->writeVarLong((double)this->initiatorId);
  if(this->otherId < 0 || this->otherId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeOkMultiCraftMessage -"<<"Forbidden value (" << this->otherId << ") on element otherId.";
  }
  output->writeVarLong((double)this->otherId);
  output->writeByte(this->role);
}

void ExchangeOkMultiCraftMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeOkMultiCraftMessage(input);
}

void ExchangeOkMultiCraftMessage::deserializeAs_ExchangeOkMultiCraftMessage(Reader *input)
{
  this->_initiatorIdFunc(input);
  this->_otherIdFunc(input);
  this->_roleFunc(input);
}

void ExchangeOkMultiCraftMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeOkMultiCraftMessage(tree);
}

void ExchangeOkMultiCraftMessage::deserializeAsyncAs_ExchangeOkMultiCraftMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeOkMultiCraftMessage::_initiatorIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeOkMultiCraftMessage::_otherIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeOkMultiCraftMessage::_roleFunc, this, std::placeholders::_1));
}

void ExchangeOkMultiCraftMessage::_initiatorIdFunc(Reader *input)
{
  this->initiatorId = input->readVarUhLong();
  if(this->initiatorId < 0 || this->initiatorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeOkMultiCraftMessage -"<<"Forbidden value (" << this->initiatorId << ") on element of ExchangeOkMultiCraftMessage.initiatorId.";
  }
}

void ExchangeOkMultiCraftMessage::_otherIdFunc(Reader *input)
{
  this->otherId = input->readVarUhLong();
  if(this->otherId < 0 || this->otherId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeOkMultiCraftMessage -"<<"Forbidden value (" << this->otherId << ") on element of ExchangeOkMultiCraftMessage.otherId.";
  }
}

void ExchangeOkMultiCraftMessage::_roleFunc(Reader *input)
{
  this->role = input->readByte();
}

ExchangeOkMultiCraftMessage::ExchangeOkMultiCraftMessage()
{
  m_type = MessageEnum::EXCHANGEOKMULTICRAFTMESSAGE;
}

