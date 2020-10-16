#include "ExchangeCraftResultMagicWithObjectDescMessage.h"

void ExchangeCraftResultMagicWithObjectDescMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeCraftResultMagicWithObjectDescMessage(output);
}

void ExchangeCraftResultMagicWithObjectDescMessage::serializeAs_ExchangeCraftResultMagicWithObjectDescMessage(Writer *output)
{
  ExchangeCraftResultWithObjectDescMessage::serializeAs_ExchangeCraftResultWithObjectDescMessage(output);
  output->writeByte(this->magicPoolStatus);
}

void ExchangeCraftResultMagicWithObjectDescMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeCraftResultMagicWithObjectDescMessage(input);
}

void ExchangeCraftResultMagicWithObjectDescMessage::deserializeAs_ExchangeCraftResultMagicWithObjectDescMessage(Reader *input)
{
  ExchangeCraftResultWithObjectDescMessage::deserialize(input);
  this->_magicPoolStatusFunc(input);
}

void ExchangeCraftResultMagicWithObjectDescMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeCraftResultMagicWithObjectDescMessage(tree);
}

void ExchangeCraftResultMagicWithObjectDescMessage::deserializeAsyncAs_ExchangeCraftResultMagicWithObjectDescMessage(FuncTree tree)
{
  ExchangeCraftResultWithObjectDescMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ExchangeCraftResultMagicWithObjectDescMessage::_magicPoolStatusFunc, this, std::placeholders::_1));
}

void ExchangeCraftResultMagicWithObjectDescMessage::_magicPoolStatusFunc(Reader *input)
{
  this->magicPoolStatus = input->readByte();
}

ExchangeCraftResultMagicWithObjectDescMessage::ExchangeCraftResultMagicWithObjectDescMessage()
{
  m_type = MessageEnum::EXCHANGECRAFTRESULTMAGICWITHOBJECTDESCMESSAGE;
}

