#include "BidExchangerObjectInfo.h"

void BidExchangerObjectInfo::serialize(Writer *output)
{
  this->serializeAs_BidExchangerObjectInfo(output);
}

void BidExchangerObjectInfo::serializeAs_BidExchangerObjectInfo(Writer *output)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - BidExchangerObjectInfo -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  output->writeVarInt((int)this->objectUID);
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - BidExchangerObjectInfo -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
  }
  output->writeVarShort((int)this->objectGID);
  if(this->objectType < 0)
  {
    qDebug()<<"ERREUR - BidExchangerObjectInfo -"<<"Forbidden value (" << this->objectType << ") on element objectType.";
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
    if(this->prices[_i5] < 0 || this->prices[_i5] > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - BidExchangerObjectInfo -"<<"Forbidden value (" << this->prices[_i5] << ") on element 5 (starting at 1) of prices.";
    }
    output->writeVarLong((double)this->prices[_i5]);
  }
}

void BidExchangerObjectInfo::deserialize(Reader *input)
{
  this->deserializeAs_BidExchangerObjectInfo(input);
}

void BidExchangerObjectInfo::deserializeAs_BidExchangerObjectInfo(Reader *input)
{
  uint _id4 = 0;
  QSharedPointer<ObjectEffect> _item4 ;
  auto _val5 = NULL;
  this->_objectUIDFunc(input);
  this->_objectGIDFunc(input);
  this->_objectTypeFunc(input);
  uint _effectsLen = input->readUShort();
  for(uint _i4 = 0; _i4 < _effectsLen; _i4++)
  {
    _id4 = input->readUShort();
    _item4 = qSharedPointerCast<ObjectEffect>(ClassManagerSingleton::get()->getClass(_id4));
    _item4->deserialize(input);
    this->effects.append(_item4);
  }
  uint _pricesLen = input->readUShort();
  for(uint _i5 = 0; _i5 < _pricesLen; _i5++)
  {
    _val5 = input->readVarUhLong();
    if(_val5 < 0 || _val5 > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - BidExchangerObjectInfo -"<<"Forbidden value (" << _val5 << ") on elements of prices.";
    }
    this->prices.append(_val5);
  }
}

void BidExchangerObjectInfo::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BidExchangerObjectInfo(tree);
}

void BidExchangerObjectInfo::deserializeAsyncAs_BidExchangerObjectInfo(FuncTree tree)
{
  tree.addChild(std::bind(&BidExchangerObjectInfo::_objectUIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BidExchangerObjectInfo::_objectGIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BidExchangerObjectInfo::_objectTypeFunc, this, std::placeholders::_1));
  this->_effectstree = tree.addChild(std::bind(&BidExchangerObjectInfo::_effectstreeFunc, this, std::placeholders::_1));
  this->_pricestree = tree.addChild(std::bind(&BidExchangerObjectInfo::_pricestreeFunc, this, std::placeholders::_1));
}

void BidExchangerObjectInfo::_objectUIDFunc(Reader *input)
{
  this->objectUID = input->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - BidExchangerObjectInfo -"<<"Forbidden value (" << this->objectUID << ") on element of BidExchangerObjectInfo.objectUID.";
  }
}

void BidExchangerObjectInfo::_objectGIDFunc(Reader *input)
{
  this->objectGID = input->readVarUhShort();
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - BidExchangerObjectInfo -"<<"Forbidden value (" << this->objectGID << ") on element of BidExchangerObjectInfo.objectGID.";
  }
}

void BidExchangerObjectInfo::_objectTypeFunc(Reader *input)
{
  this->objectType = input->readInt();
  if(this->objectType < 0)
  {
    qDebug()<<"ERREUR - BidExchangerObjectInfo -"<<"Forbidden value (" << this->objectType << ") on element of BidExchangerObjectInfo.objectType.";
  }
}

void BidExchangerObjectInfo::_effectstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_effectstree.addChild(std::bind(&BidExchangerObjectInfo::_effectsFunc, this, std::placeholders::_1));
  }
}

void BidExchangerObjectInfo::_effectsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<ObjectEffect> _item = qSharedPointerCast<ObjectEffect>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->effects.append(_item);
}

void BidExchangerObjectInfo::_pricestreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_pricestree.addChild(std::bind(&BidExchangerObjectInfo::_pricesFunc, this, std::placeholders::_1));
  }
}

void BidExchangerObjectInfo::_pricesFunc(Reader *input)
{
  double _val = input->readVarUhLong();
  if(_val < 0 || _val > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - BidExchangerObjectInfo -"<<"Forbidden value (" << _val << ") on elements of prices.";
  }
  this->prices.append(_val);
}

BidExchangerObjectInfo::BidExchangerObjectInfo()
{
  m_types<<ClassEnum::BIDEXCHANGEROBJECTINFO;
}

bool BidExchangerObjectInfo::operator==(const BidExchangerObjectInfo &compared)
{
  if(objectUID == compared.objectUID)
  if(objectGID == compared.objectGID)
  if(objectType == compared.objectType)
  if(effects == compared.effects)
  if(prices == compared.prices)
  if(_effectstree == compared._effectstree)
  if(_pricestree == compared._pricestree)
  return true;
  
  return false;
}

