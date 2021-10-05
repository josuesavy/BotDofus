#include "ExchangeCraftCountModifiedMessage.h"

void ExchangeCraftCountModifiedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeCraftCountModifiedMessage(output);
}

void ExchangeCraftCountModifiedMessage::serializeAs_ExchangeCraftCountModifiedMessage(Writer *output)
{
  output->writeVarInt((int)this->count);
}

void ExchangeCraftCountModifiedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeCraftCountModifiedMessage(input);
}

void ExchangeCraftCountModifiedMessage::deserializeAs_ExchangeCraftCountModifiedMessage(Reader *input)
{
  this->_countFunc(input);
}

void ExchangeCraftCountModifiedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeCraftCountModifiedMessage(tree);
}

void ExchangeCraftCountModifiedMessage::deserializeAsyncAs_ExchangeCraftCountModifiedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeCraftCountModifiedMessage::_countFunc, this, std::placeholders::_1));
}

void ExchangeCraftCountModifiedMessage::_countFunc(Reader *input)
{
  this->count = input->readVarInt();
}

ExchangeCraftCountModifiedMessage::ExchangeCraftCountModifiedMessage()
{
  m_type = MessageEnum::EXCHANGECRAFTCOUNTMODIFIEDMESSAGE;
}

