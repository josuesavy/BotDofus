#include "ExchangePlayerMultiCraftRequestMessage.h"

void ExchangePlayerMultiCraftRequestMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangePlayerMultiCraftRequestMessage(output);
}

void ExchangePlayerMultiCraftRequestMessage::serializeAs_ExchangePlayerMultiCraftRequestMessage(Writer *output)
{
  ExchangeRequestMessage::serializeAs_ExchangeRequestMessage(output);
  if(this->target < 0 || this->target > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangePlayerMultiCraftRequestMessage -"<<"Forbidden value (" << this->target << ") on element target.";
  }
  output->writeVarLong((double)this->target);
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - ExchangePlayerMultiCraftRequestMessage -"<<"Forbidden value (" << this->skillId << ") on element skillId.";
  }
  output->writeVarInt((int)this->skillId);
}

void ExchangePlayerMultiCraftRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangePlayerMultiCraftRequestMessage(input);
}

void ExchangePlayerMultiCraftRequestMessage::deserializeAs_ExchangePlayerMultiCraftRequestMessage(Reader *input)
{
  ExchangeRequestMessage::deserialize(input);
  this->_targetFunc(input);
  this->_skillIdFunc(input);
}

void ExchangePlayerMultiCraftRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangePlayerMultiCraftRequestMessage(tree);
}

void ExchangePlayerMultiCraftRequestMessage::deserializeAsyncAs_ExchangePlayerMultiCraftRequestMessage(FuncTree tree)
{
  ExchangeRequestMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ExchangePlayerMultiCraftRequestMessage::_targetFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangePlayerMultiCraftRequestMessage::_skillIdFunc, this, std::placeholders::_1));
}

void ExchangePlayerMultiCraftRequestMessage::_targetFunc(Reader *input)
{
  this->target = input->readVarUhLong();
  if(this->target < 0 || this->target > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangePlayerMultiCraftRequestMessage -"<<"Forbidden value (" << this->target << ") on element of ExchangePlayerMultiCraftRequestMessage.target.";
  }
}

void ExchangePlayerMultiCraftRequestMessage::_skillIdFunc(Reader *input)
{
  this->skillId = input->readVarUhInt();
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - ExchangePlayerMultiCraftRequestMessage -"<<"Forbidden value (" << this->skillId << ") on element of ExchangePlayerMultiCraftRequestMessage.skillId.";
  }
}

ExchangePlayerMultiCraftRequestMessage::ExchangePlayerMultiCraftRequestMessage()
{
  m_type = MessageEnum::EXCHANGEPLAYERMULTICRAFTREQUESTMESSAGE;
  m_needsHash = true;
}

