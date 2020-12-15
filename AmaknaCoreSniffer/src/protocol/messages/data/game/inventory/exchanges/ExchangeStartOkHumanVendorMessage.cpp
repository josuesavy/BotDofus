#include "ExchangeStartOkHumanVendorMessage.h"

void ExchangeStartOkHumanVendorMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeStartOkHumanVendorMessage(output);
}

void ExchangeStartOkHumanVendorMessage::serializeAs_ExchangeStartOkHumanVendorMessage(Writer *output)
{
  if(this->sellerId < -9.007199254740992E15 || this->sellerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeStartOkHumanVendorMessage -"<<"Forbidden value (" << this->sellerId << ") on element sellerId.";
  }
  output->writeDouble(this->sellerId);
  output->writeShort((short)this->objectsInfos.size());
  for(uint _i2 = 0; _i2 < this->objectsInfos.size(); _i2++)
  {
    qSharedPointerCast<ObjectItemToSellInHumanVendorShop>(this->objectsInfos[_i2])->serializeAs_ObjectItemToSellInHumanVendorShop(output);
  }
}

void ExchangeStartOkHumanVendorMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeStartOkHumanVendorMessage(input);
}

void ExchangeStartOkHumanVendorMessage::deserializeAs_ExchangeStartOkHumanVendorMessage(Reader *input)
{
  QSharedPointer<ObjectItemToSellInHumanVendorShop> _item2 ;
  this->_sellerIdFunc(input);
  uint _objectsInfosLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _objectsInfosLen; _i2++)
  {
    _item2 = QSharedPointer<ObjectItemToSellInHumanVendorShop>(new ObjectItemToSellInHumanVendorShop() );
    _item2->deserialize(input);
    this->objectsInfos.append(_item2);
  }
}

void ExchangeStartOkHumanVendorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeStartOkHumanVendorMessage(tree);
}

void ExchangeStartOkHumanVendorMessage::deserializeAsyncAs_ExchangeStartOkHumanVendorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeStartOkHumanVendorMessage::_sellerIdFunc, this, std::placeholders::_1));
  this->_objectsInfostree = tree.addChild(std::bind(&ExchangeStartOkHumanVendorMessage::_objectsInfostreeFunc, this, std::placeholders::_1));
}

void ExchangeStartOkHumanVendorMessage::_sellerIdFunc(Reader *input)
{
  this->sellerId = input->readDouble();
  if(this->sellerId < -9.007199254740992E15 || this->sellerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeStartOkHumanVendorMessage -"<<"Forbidden value (" << this->sellerId << ") on element of ExchangeStartOkHumanVendorMessage.sellerId.";
  }
}

void ExchangeStartOkHumanVendorMessage::_objectsInfostreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_objectsInfostree.addChild(std::bind(&ExchangeStartOkHumanVendorMessage::_objectsInfosFunc, this, std::placeholders::_1));
  }
}

void ExchangeStartOkHumanVendorMessage::_objectsInfosFunc(Reader *input)
{
  QSharedPointer<ObjectItemToSellInHumanVendorShop> _item = QSharedPointer<ObjectItemToSellInHumanVendorShop>(new ObjectItemToSellInHumanVendorShop() );
  _item->deserialize(input);
  this->objectsInfos.append(_item);
}

ExchangeStartOkHumanVendorMessage::ExchangeStartOkHumanVendorMessage()
{
  m_type = MessageEnum::EXCHANGESTARTOKHUMANVENDORMESSAGE;
}

