#include "ExchangeStartOkMulticraftCrafterMessage.h"

void ExchangeStartOkMulticraftCrafterMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeStartOkMulticraftCrafterMessage(output);
}

void ExchangeStartOkMulticraftCrafterMessage::serializeAs_ExchangeStartOkMulticraftCrafterMessage(Writer *output)
{
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkMulticraftCrafterMessage -"<<"Forbidden value (" << this->skillId << ") on element skillId.";
  }
  output->writeVarInt((int)this->skillId);
}

void ExchangeStartOkMulticraftCrafterMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeStartOkMulticraftCrafterMessage(input);
}

void ExchangeStartOkMulticraftCrafterMessage::deserializeAs_ExchangeStartOkMulticraftCrafterMessage(Reader *input)
{
  this->_skillIdFunc(input);
}

void ExchangeStartOkMulticraftCrafterMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeStartOkMulticraftCrafterMessage(tree);
}

void ExchangeStartOkMulticraftCrafterMessage::deserializeAsyncAs_ExchangeStartOkMulticraftCrafterMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeStartOkMulticraftCrafterMessage::_skillIdFunc, this, std::placeholders::_1));
}

void ExchangeStartOkMulticraftCrafterMessage::_skillIdFunc(Reader *input)
{
  this->skillId = input->readVarUhInt();
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkMulticraftCrafterMessage -"<<"Forbidden value (" << this->skillId << ") on element of ExchangeStartOkMulticraftCrafterMessage.skillId.";
  }
}

ExchangeStartOkMulticraftCrafterMessage::ExchangeStartOkMulticraftCrafterMessage()
{
  m_type = MessageEnum::EXCHANGESTARTOKMULTICRAFTCRAFTERMESSAGE;
}

