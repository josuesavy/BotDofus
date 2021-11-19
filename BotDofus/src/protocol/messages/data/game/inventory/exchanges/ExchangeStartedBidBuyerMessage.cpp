#include "ExchangeStartedBidBuyerMessage.h"

void ExchangeStartedBidBuyerMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeStartedBidBuyerMessage(output);
}

void ExchangeStartedBidBuyerMessage::serializeAs_ExchangeStartedBidBuyerMessage(Writer *output)
{
  this->buyerDescriptor.serializeAs_SellerBuyerDescriptor(output);
}

void ExchangeStartedBidBuyerMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeStartedBidBuyerMessage(input);
}

void ExchangeStartedBidBuyerMessage::deserializeAs_ExchangeStartedBidBuyerMessage(Reader *input)
{
  this->buyerDescriptor = SellerBuyerDescriptor();
  this->buyerDescriptor.deserialize(input);
}

void ExchangeStartedBidBuyerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeStartedBidBuyerMessage(tree);
}

void ExchangeStartedBidBuyerMessage::deserializeAsyncAs_ExchangeStartedBidBuyerMessage(FuncTree tree)
{
  this->_buyerDescriptortree = tree.addChild(std::bind(&ExchangeStartedBidBuyerMessage::_buyerDescriptortreeFunc, this, std::placeholders::_1));
}

void ExchangeStartedBidBuyerMessage::_buyerDescriptortreeFunc(Reader *input)
{
  this->buyerDescriptor = SellerBuyerDescriptor();
  this->buyerDescriptor.deserializeAsync(this->_buyerDescriptortree);
}

ExchangeStartedBidBuyerMessage::ExchangeStartedBidBuyerMessage()
{
  m_type = MessageEnum::EXCHANGESTARTEDBIDBUYERMESSAGE;
}

