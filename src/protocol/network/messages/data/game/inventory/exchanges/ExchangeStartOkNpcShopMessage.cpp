#include "ExchangeStartOkNpcShopMessage.h"

void ExchangeStartOkNpcShopMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeStartOkNpcShopMessage(output);
}

void ExchangeStartOkNpcShopMessage::serializeAs_ExchangeStartOkNpcShopMessage(Writer *output)
{
  if(this->npcSellerId < -9007199254740992 || this->npcSellerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeStartOkNpcShopMessage -"<<"Forbidden value (" << this->npcSellerId << ") on element npcSellerId.";
  }
  output->writeDouble(this->npcSellerId);
  if(this->tokenId < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkNpcShopMessage -"<<"Forbidden value (" << this->tokenId << ") on element tokenId.";
  }
  output->writeVarInt((int)this->tokenId);
  output->writeShort((short)this->objectsInfos.size());
  for(uint _i3 = 0; _i3 < this->objectsInfos.size(); _i3++)
  {
    qSharedPointerCast<ObjectItemToSellInNpcShop>(this->objectsInfos[_i3])->serializeAs_ObjectItemToSellInNpcShop(output);
  }
}

void ExchangeStartOkNpcShopMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeStartOkNpcShopMessage(input);
}

void ExchangeStartOkNpcShopMessage::deserializeAs_ExchangeStartOkNpcShopMessage(Reader *input)
{
  QSharedPointer<ObjectItemToSellInNpcShop> _item3 ;
  this->_npcSellerIdFunc(input);
  this->_tokenIdFunc(input);
  uint _objectsInfosLen = uint(input->readUShort());
  for(uint _i3 = 0; _i3 < _objectsInfosLen; _i3++)
  {
    _item3 = QSharedPointer<ObjectItemToSellInNpcShop>(new ObjectItemToSellInNpcShop() );
    _item3->deserialize(input);
    this->objectsInfos.append(_item3);
  }
}

void ExchangeStartOkNpcShopMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeStartOkNpcShopMessage(tree);
}

void ExchangeStartOkNpcShopMessage::deserializeAsyncAs_ExchangeStartOkNpcShopMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeStartOkNpcShopMessage::_npcSellerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeStartOkNpcShopMessage::_tokenIdFunc, this, std::placeholders::_1));
  this->_objectsInfostree = tree.addChild(std::bind(&ExchangeStartOkNpcShopMessage::_objectsInfostreeFunc, this, std::placeholders::_1));
}

void ExchangeStartOkNpcShopMessage::_npcSellerIdFunc(Reader *input)
{
  this->npcSellerId = input->readDouble();
  if(this->npcSellerId < -9007199254740992 || this->npcSellerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeStartOkNpcShopMessage -"<<"Forbidden value (" << this->npcSellerId << ") on element of ExchangeStartOkNpcShopMessage.npcSellerId.";
  }
}

void ExchangeStartOkNpcShopMessage::_tokenIdFunc(Reader *input)
{
  this->tokenId = input->readVarUhInt();
  if(this->tokenId < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkNpcShopMessage -"<<"Forbidden value (" << this->tokenId << ") on element of ExchangeStartOkNpcShopMessage.tokenId.";
  }
}

void ExchangeStartOkNpcShopMessage::_objectsInfostreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_objectsInfostree.addChild(std::bind(&ExchangeStartOkNpcShopMessage::_objectsInfosFunc, this, std::placeholders::_1));
  }
}

void ExchangeStartOkNpcShopMessage::_objectsInfosFunc(Reader *input)
{
  QSharedPointer<ObjectItemToSellInNpcShop> _item = QSharedPointer<ObjectItemToSellInNpcShop>(new ObjectItemToSellInNpcShop() );
  _item->deserialize(input);
  this->objectsInfos.append(_item);
}

ExchangeStartOkNpcShopMessage::ExchangeStartOkNpcShopMessage()
{
  m_type = MessageEnum::EXCHANGESTARTOKNPCSHOPMESSAGE;
}

