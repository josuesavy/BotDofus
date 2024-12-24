#include "ExchangeStartedBidSellerMessage.h"

void ExchangeStartedBidSellerMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeStartedBidSellerMessage(output);
}

void ExchangeStartedBidSellerMessage::serializeAs_ExchangeStartedBidSellerMessage(Writer *output)
{
  this->sellerDescriptor.serializeAs_SellerBuyerDescriptor(output);
  output->writeShort((short)this->objectsInfos.size());
  for(uint _i2 = 0; _i2 < this->objectsInfos.size(); _i2++)
  {
    qSharedPointerCast<ObjectItemToSellInBid>(this->objectsInfos[_i2])->serializeAs_ObjectItemToSellInBid(output);
  }
}

void ExchangeStartedBidSellerMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeStartedBidSellerMessage(input);
}

void ExchangeStartedBidSellerMessage::deserializeAs_ExchangeStartedBidSellerMessage(Reader *input)
{
  QSharedPointer<ObjectItemToSellInBid> _item2 ;
  this->sellerDescriptor = SellerBuyerDescriptor();
  this->sellerDescriptor.deserialize(input);
  uint _objectsInfosLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _objectsInfosLen; _i2++)
  {
    _item2 = QSharedPointer<ObjectItemToSellInBid>(new ObjectItemToSellInBid() );
    _item2->deserialize(input);
    this->objectsInfos.append(_item2);
  }
}

void ExchangeStartedBidSellerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeStartedBidSellerMessage(tree);
}

void ExchangeStartedBidSellerMessage::deserializeAsyncAs_ExchangeStartedBidSellerMessage(FuncTree tree)
{
  this->_sellerDescriptortree = tree.addChild(std::bind(&ExchangeStartedBidSellerMessage::_sellerDescriptortreeFunc, this, std::placeholders::_1));
  this->_objectsInfostree = tree.addChild(std::bind(&ExchangeStartedBidSellerMessage::_objectsInfostreeFunc, this, std::placeholders::_1));
}

void ExchangeStartedBidSellerMessage::_sellerDescriptortreeFunc(Reader *input)
{
  this->sellerDescriptor = SellerBuyerDescriptor();
  this->sellerDescriptor.deserializeAsync(this->_sellerDescriptortree);
}

void ExchangeStartedBidSellerMessage::_objectsInfostreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_objectsInfostree.addChild(std::bind(&ExchangeStartedBidSellerMessage::_objectsInfosFunc, this, std::placeholders::_1));
  }
}

void ExchangeStartedBidSellerMessage::_objectsInfosFunc(Reader *input)
{
  QSharedPointer<ObjectItemToSellInBid> _item = QSharedPointer<ObjectItemToSellInBid>(new ObjectItemToSellInBid() );
  _item->deserialize(input);
  this->objectsInfos.append(_item);
}

ExchangeStartedBidSellerMessage::ExchangeStartedBidSellerMessage()
{
  m_type = MessageEnum::EXCHANGESTARTEDBIDSELLERMESSAGE;
}

