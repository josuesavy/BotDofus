#include "ExchangeCraftCountRequestMessage.h"

void ExchangeCraftCountRequestMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeCraftCountRequestMessage(output);
}

void ExchangeCraftCountRequestMessage::serializeAs_ExchangeCraftCountRequestMessage(Writer *output)
{
  output->writeVarInt((int)this->count);
}

void ExchangeCraftCountRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeCraftCountRequestMessage(input);
}

void ExchangeCraftCountRequestMessage::deserializeAs_ExchangeCraftCountRequestMessage(Reader *input)
{
  this->_countFunc(input);
}

void ExchangeCraftCountRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeCraftCountRequestMessage(tree);
}

void ExchangeCraftCountRequestMessage::deserializeAsyncAs_ExchangeCraftCountRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeCraftCountRequestMessage::_countFunc, this, std::placeholders::_1));
}

void ExchangeCraftCountRequestMessage::_countFunc(Reader *input)
{
  this->count = input->readVarInt();
}

ExchangeCraftCountRequestMessage::ExchangeCraftCountRequestMessage()
{
  m_type = MessageEnum::EXCHANGECRAFTCOUNTREQUESTMESSAGE;
}

