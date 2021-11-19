#include "ExchangeStartOkMulticraftCustomerMessage.h"

void ExchangeStartOkMulticraftCustomerMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeStartOkMulticraftCustomerMessage(output);
}

void ExchangeStartOkMulticraftCustomerMessage::serializeAs_ExchangeStartOkMulticraftCustomerMessage(Writer *output)
{
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkMulticraftCustomerMessage -"<<"Forbidden value (" << this->skillId << ") on element skillId.";
  }
  output->writeVarInt((int)this->skillId);
  if(this->crafterJobLevel < 0 || this->crafterJobLevel > 255)
  {
    qDebug()<<"ERREUR - ExchangeStartOkMulticraftCustomerMessage -"<<"Forbidden value (" << this->crafterJobLevel << ") on element crafterJobLevel.";
  }
  output->writeByte(this->crafterJobLevel);
}

void ExchangeStartOkMulticraftCustomerMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeStartOkMulticraftCustomerMessage(input);
}

void ExchangeStartOkMulticraftCustomerMessage::deserializeAs_ExchangeStartOkMulticraftCustomerMessage(Reader *input)
{
  this->_skillIdFunc(input);
  this->_crafterJobLevelFunc(input);
}

void ExchangeStartOkMulticraftCustomerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeStartOkMulticraftCustomerMessage(tree);
}

void ExchangeStartOkMulticraftCustomerMessage::deserializeAsyncAs_ExchangeStartOkMulticraftCustomerMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeStartOkMulticraftCustomerMessage::_skillIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeStartOkMulticraftCustomerMessage::_crafterJobLevelFunc, this, std::placeholders::_1));
}

void ExchangeStartOkMulticraftCustomerMessage::_skillIdFunc(Reader *input)
{
  this->skillId = input->readVarUhInt();
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkMulticraftCustomerMessage -"<<"Forbidden value (" << this->skillId << ") on element of ExchangeStartOkMulticraftCustomerMessage.skillId.";
  }
}

void ExchangeStartOkMulticraftCustomerMessage::_crafterJobLevelFunc(Reader *input)
{
  this->crafterJobLevel = input->readUByte();
  if(this->crafterJobLevel < 0 || this->crafterJobLevel > 255)
  {
    qDebug()<<"ERREUR - ExchangeStartOkMulticraftCustomerMessage -"<<"Forbidden value (" << this->crafterJobLevel << ") on element of ExchangeStartOkMulticraftCustomerMessage.crafterJobLevel.";
  }
}

ExchangeStartOkMulticraftCustomerMessage::ExchangeStartOkMulticraftCustomerMessage()
{
  m_type = MessageEnum::EXCHANGESTARTOKMULTICRAFTCUSTOMERMESSAGE;
}

