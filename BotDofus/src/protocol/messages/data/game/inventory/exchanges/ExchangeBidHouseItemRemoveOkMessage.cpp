#include "ExchangeBidHouseItemRemoveOkMessage.h"

void ExchangeBidHouseItemRemoveOkMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeBidHouseItemRemoveOkMessage(output);
}

void ExchangeBidHouseItemRemoveOkMessage::serializeAs_ExchangeBidHouseItemRemoveOkMessage(Writer *output)
{
  output->writeInt((int)this->sellerId);
}

void ExchangeBidHouseItemRemoveOkMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeBidHouseItemRemoveOkMessage(input);
}

void ExchangeBidHouseItemRemoveOkMessage::deserializeAs_ExchangeBidHouseItemRemoveOkMessage(Reader *input)
{
  this->_sellerIdFunc(input);
}

void ExchangeBidHouseItemRemoveOkMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeBidHouseItemRemoveOkMessage(tree);
}

void ExchangeBidHouseItemRemoveOkMessage::deserializeAsyncAs_ExchangeBidHouseItemRemoveOkMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeBidHouseItemRemoveOkMessage::_sellerIdFunc, this, std::placeholders::_1));
}

void ExchangeBidHouseItemRemoveOkMessage::_sellerIdFunc(Reader *input)
{
  this->sellerId = input->readInt();
}

ExchangeBidHouseItemRemoveOkMessage::ExchangeBidHouseItemRemoveOkMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSEITEMREMOVEOKMESSAGE;
}

