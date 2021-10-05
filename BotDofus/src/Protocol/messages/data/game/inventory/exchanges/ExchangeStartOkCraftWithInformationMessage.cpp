#include "ExchangeStartOkCraftWithInformationMessage.h"

void ExchangeStartOkCraftWithInformationMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeStartOkCraftWithInformationMessage(output);
}

void ExchangeStartOkCraftWithInformationMessage::serializeAs_ExchangeStartOkCraftWithInformationMessage(Writer *output)
{
  ExchangeStartOkCraftMessage::serializeAs_ExchangeStartOkCraftMessage(output);
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkCraftWithInformationMessage -"<<"Forbidden value (" << this->skillId << ") on element skillId.";
  }
  output->writeVarInt((int)this->skillId);
}

void ExchangeStartOkCraftWithInformationMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeStartOkCraftWithInformationMessage(input);
}

void ExchangeStartOkCraftWithInformationMessage::deserializeAs_ExchangeStartOkCraftWithInformationMessage(Reader *input)
{
  ExchangeStartOkCraftMessage::deserialize(input);
  this->_skillIdFunc(input);
}

void ExchangeStartOkCraftWithInformationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeStartOkCraftWithInformationMessage(tree);
}

void ExchangeStartOkCraftWithInformationMessage::deserializeAsyncAs_ExchangeStartOkCraftWithInformationMessage(FuncTree tree)
{
  ExchangeStartOkCraftMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ExchangeStartOkCraftWithInformationMessage::_skillIdFunc, this, std::placeholders::_1));
}

void ExchangeStartOkCraftWithInformationMessage::_skillIdFunc(Reader *input)
{
  this->skillId = input->readVarUhInt();
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkCraftWithInformationMessage -"<<"Forbidden value (" << this->skillId << ") on element of ExchangeStartOkCraftWithInformationMessage.skillId.";
  }
}

ExchangeStartOkCraftWithInformationMessage::ExchangeStartOkCraftWithInformationMessage()
{
  m_type = MessageEnum::EXCHANGESTARTOKCRAFTWITHINFORMATIONMESSAGE;
}

