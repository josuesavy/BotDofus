#include "ExchangeBidHouseInListAddedMessage.h"

void ExchangeBidHouseInListAddedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeBidHouseInListAddedMessage(output);
}

void ExchangeBidHouseInListAddedMessage::serializeAs_ExchangeBidHouseInListAddedMessage(Writer *output)
{
  output->writeInt((int)this->itemUID);
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseInListAddedMessage -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
  }
  output->writeVarInt((int)this->objectGID);
  if(this->objectType < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseInListAddedMessage -"<<"Forbidden value (" << this->objectType << ") on element objectType.";
  }
  output->writeInt((int)this->objectType);
  output->writeShort((short)this->effects.size());
  for(uint _i4 = 0; _i4 < this->effects.size(); _i4++)
  {
    output->writeShort((short)qSharedPointerCast<ObjectEffect>(this->effects[_i4])->getTypes().last());
    qSharedPointerCast<ObjectEffect>(this->effects[_i4])->serialize(output);
  }
  output->writeShort((short)this->prices.size());
  for(uint _i5 = 0; _i5 < this->prices.size(); _i5++)
  {
    if(this->prices[_i5] < 0 || this->prices[_i5] > 9007199254740992)
    {
      qDebug()<<"ERREUR - ExchangeBidHouseInListAddedMessage -"<<"Forbidden value (" << this->prices[_i5] << ") on element 5 (starting at 1) of prices.";
    }
    output->writeVarLong((double)this->prices[_i5]);
  }
}

void ExchangeBidHouseInListAddedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeBidHouseInListAddedMessage(input);
}

void ExchangeBidHouseInListAddedMessage::deserializeAs_ExchangeBidHouseInListAddedMessage(Reader *input)
{
  uint _id4 = 0;
  QSharedPointer<ObjectEffect> _item4 ;
  double _val5 = NULL;
  this->_itemUIDFunc(input);
  this->_objectGIDFunc(input);
  this->_objectTypeFunc(input);
  uint _effectsLen = uint(input->readUShort());
  for(uint _i4 = 0; _i4 < _effectsLen; _i4++)
  {
    _id4 = uint(input->readUShort());
    _item4 = qSharedPointerCast<ObjectEffect>(ClassManagerSingleton::get()->getClass(_id4));
    _item4->deserialize(input);
    this->effects.append(_item4);
  }
  uint _pricesLen = uint(input->readUShort());
  for(uint _i5 = 0; _i5 < _pricesLen; _i5++)
  {
    _val5 = input->readVarUhLong();
    if(_val5 < 0 || _val5 > 9007199254740992)
    {
      qDebug()<<"ERREUR - ExchangeBidHouseInListAddedMessage -"<<"Forbidden value (" << _val5 << ") on elements of prices.";
    }
    this->prices.append(_val5);
  }
}

void ExchangeBidHouseInListAddedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeBidHouseInListAddedMessage(tree);
}

void ExchangeBidHouseInListAddedMessage::deserializeAsyncAs_ExchangeBidHouseInListAddedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeBidHouseInListAddedMessage::_itemUIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeBidHouseInListAddedMessage::_objectGIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeBidHouseInListAddedMessage::_objectTypeFunc, this, std::placeholders::_1));
  this->_effectstree = tree.addChild(std::bind(&ExchangeBidHouseInListAddedMessage::_effectstreeFunc, this, std::placeholders::_1));
  this->_pricestree = tree.addChild(std::bind(&ExchangeBidHouseInListAddedMessage::_pricestreeFunc, this, std::placeholders::_1));
}

void ExchangeBidHouseInListAddedMessage::_itemUIDFunc(Reader *input)
{
  this->itemUID = input->readInt();
}

void ExchangeBidHouseInListAddedMessage::_objectGIDFunc(Reader *input)
{
  this->objectGID = input->readVarUhInt();
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseInListAddedMessage -"<<"Forbidden value (" << this->objectGID << ") on element of ExchangeBidHouseInListAddedMessage.objectGID.";
  }
}

void ExchangeBidHouseInListAddedMessage::_objectTypeFunc(Reader *input)
{
  this->objectType = input->readInt();
  if(this->objectType < 0)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseInListAddedMessage -"<<"Forbidden value (" << this->objectType << ") on element of ExchangeBidHouseInListAddedMessage.objectType.";
  }
}

void ExchangeBidHouseInListAddedMessage::_effectstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_effectstree.addChild(std::bind(&ExchangeBidHouseInListAddedMessage::_effectsFunc, this, std::placeholders::_1));
  }
}

void ExchangeBidHouseInListAddedMessage::_effectsFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<ObjectEffect> _item = qSharedPointerCast<ObjectEffect>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->effects.append(_item);
}

void ExchangeBidHouseInListAddedMessage::_pricestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_pricestree.addChild(std::bind(&ExchangeBidHouseInListAddedMessage::_pricesFunc, this, std::placeholders::_1));
  }
}

void ExchangeBidHouseInListAddedMessage::_pricesFunc(Reader *input)
{
  double _val = input->readVarUhLong();
  if(_val < 0 || _val > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeBidHouseInListAddedMessage -"<<"Forbidden value (" << _val << ") on elements of prices.";
  }
  this->prices.append(_val);
}

ExchangeBidHouseInListAddedMessage::ExchangeBidHouseInListAddedMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSEINLISTADDEDMESSAGE;
}

