#include "ExchangeBidHouseItemAddOkMessage.h"

void ExchangeBidHouseItemAddOkMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeBidHouseItemAddOkMessage(output);
}

void ExchangeBidHouseItemAddOkMessage::serializeAs_ExchangeBidHouseItemAddOkMessage(Writer *output)
{
  this->itemInfo->serializeAs_ObjectItemToSellInBid(output);
}

void ExchangeBidHouseItemAddOkMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeBidHouseItemAddOkMessage(input);
}

void ExchangeBidHouseItemAddOkMessage::deserializeAs_ExchangeBidHouseItemAddOkMessage(Reader *input)
{
  this->itemInfo = QSharedPointer<ObjectItemToSellInBid>(new ObjectItemToSellInBid() );
  this->itemInfo->deserialize(input);
}

void ExchangeBidHouseItemAddOkMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeBidHouseItemAddOkMessage(tree);
}

void ExchangeBidHouseItemAddOkMessage::deserializeAsyncAs_ExchangeBidHouseItemAddOkMessage(FuncTree tree)
{
  this->_itemInfotree = tree.addChild(std::bind(&ExchangeBidHouseItemAddOkMessage::_itemInfotreeFunc, this, std::placeholders::_1));
}

void ExchangeBidHouseItemAddOkMessage::_itemInfotreeFunc(Reader *input)
{
  this->itemInfo = QSharedPointer<ObjectItemToSellInBid>(new ObjectItemToSellInBid() );
  this->itemInfo->deserializeAsync(this->_itemInfotree);
}

ExchangeBidHouseItemAddOkMessage::ExchangeBidHouseItemAddOkMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSEITEMADDOKMESSAGE;
}

