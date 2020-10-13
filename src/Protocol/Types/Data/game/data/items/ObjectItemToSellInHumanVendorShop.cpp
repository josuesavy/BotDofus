#include "ObjectItemToSellInHumanVendorShop.h"

void ObjectItemToSellInHumanVendorShop::serialize(Writer *output)
{
  this->serializeAs_ObjectItemToSellInHumanVendorShop(output);
}

void ObjectItemToSellInHumanVendorShop::serializeAs_ObjectItemToSellInHumanVendorShop(Writer *output)
{
  Item::serializeAs_Item(output);
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemToSellInHumanVendorShop -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
  }
  output->writeVarShort((int)this->objectGID);
  output->writeShort((short)this->effects.size());
  for(uint _i2 = 0; _i2 < this->effects.size(); _i2++)
  {
    output->writeShort((short)qSharedPointerCast<ObjectEffect>(this->effects[_i2])->getTypes().last());
    qSharedPointerCast<ObjectEffect>(this->effects[_i2])->serialize(output);
  }
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemToSellInHumanVendorShop -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  output->writeVarInt((int)this->objectUID);
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectItemToSellInHumanVendorShop -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
  }
  output->writeVarInt((int)this->quantity);
  if(this->objectPrice < 0 || this->objectPrice > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ObjectItemToSellInHumanVendorShop -"<<"Forbidden value (" << this->objectPrice << ") on element objectPrice.";
  }
  output->writeVarLong((double)this->objectPrice);
  if(this->publicPrice < 0 || this->publicPrice > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ObjectItemToSellInHumanVendorShop -"<<"Forbidden value (" << this->publicPrice << ") on element publicPrice.";
  }
  output->writeVarLong((double)this->publicPrice);
}

void ObjectItemToSellInHumanVendorShop::deserialize(Reader *input)
{
  this->deserializeAs_ObjectItemToSellInHumanVendorShop(input);
}

void ObjectItemToSellInHumanVendorShop::deserializeAs_ObjectItemToSellInHumanVendorShop(Reader *input)
{
  uint _id2 = 0;
  QSharedPointer<ObjectEffect> _item2 ;
  Item::deserialize(input);
  this->_objectGIDFunc(input);
  uint _effectsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _effectsLen; _i2++)
  {
    _id2 = input->readUShort();
    _item2 = qSharedPointerCast<ObjectEffect>(ClassManagerSingleton::get()->getClass(_id2));
    _item2->deserialize(input);
    this->effects.append(_item2);
  }
  this->_objectUIDFunc(input);
  this->_quantityFunc(input);
  this->_objectPriceFunc(input);
  this->_publicPriceFunc(input);
}

void ObjectItemToSellInHumanVendorShop::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectItemToSellInHumanVendorShop(tree);
}

void ObjectItemToSellInHumanVendorShop::deserializeAsyncAs_ObjectItemToSellInHumanVendorShop(FuncTree tree)
{
  Item::deserializeAsync(tree);
  tree.addChild(std::bind(&ObjectItemToSellInHumanVendorShop::_objectGIDFunc, this, std::placeholders::_1));
  this->_effectstree = tree.addChild(std::bind(&ObjectItemToSellInHumanVendorShop::_effectstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectItemToSellInHumanVendorShop::_objectUIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectItemToSellInHumanVendorShop::_quantityFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectItemToSellInHumanVendorShop::_objectPriceFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectItemToSellInHumanVendorShop::_publicPriceFunc, this, std::placeholders::_1));
}

void ObjectItemToSellInHumanVendorShop::_objectGIDFunc(Reader *input)
{
  this->objectGID = input->readVarUhShort();
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemToSellInHumanVendorShop -"<<"Forbidden value (" << this->objectGID << ") on element of ObjectItemToSellInHumanVendorShop.objectGID.";
  }
}

void ObjectItemToSellInHumanVendorShop::_effectstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_effectstree.addChild(std::bind(&ObjectItemToSellInHumanVendorShop::_effectsFunc, this, std::placeholders::_1));
  }
}

void ObjectItemToSellInHumanVendorShop::_effectsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<ObjectEffect> _item = qSharedPointerCast<ObjectEffect>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->effects.append(_item);
}

void ObjectItemToSellInHumanVendorShop::_objectUIDFunc(Reader *input)
{
  this->objectUID = input->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemToSellInHumanVendorShop -"<<"Forbidden value (" << this->objectUID << ") on element of ObjectItemToSellInHumanVendorShop.objectUID.";
  }
}

void ObjectItemToSellInHumanVendorShop::_quantityFunc(Reader *input)
{
  this->quantity = input->readVarUhInt();
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectItemToSellInHumanVendorShop -"<<"Forbidden value (" << this->quantity << ") on element of ObjectItemToSellInHumanVendorShop.quantity.";
  }
}

void ObjectItemToSellInHumanVendorShop::_objectPriceFunc(Reader *input)
{
  this->objectPrice = input->readVarUhLong();
  if(this->objectPrice < 0 || this->objectPrice > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ObjectItemToSellInHumanVendorShop -"<<"Forbidden value (" << this->objectPrice << ") on element of ObjectItemToSellInHumanVendorShop.objectPrice.";
  }
}

void ObjectItemToSellInHumanVendorShop::_publicPriceFunc(Reader *input)
{
  this->publicPrice = input->readVarUhLong();
  if(this->publicPrice < 0 || this->publicPrice > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ObjectItemToSellInHumanVendorShop -"<<"Forbidden value (" << this->publicPrice << ") on element of ObjectItemToSellInHumanVendorShop.publicPrice.";
  }
}

ObjectItemToSellInHumanVendorShop::ObjectItemToSellInHumanVendorShop()
{
  m_types<<ClassEnum::OBJECTITEMTOSELLINHUMANVENDORSHOP;
}

bool ObjectItemToSellInHumanVendorShop::operator==(const ObjectItemToSellInHumanVendorShop &compared)
{
  if(objectGID == compared.objectGID)
  if(effects == compared.effects)
  if(objectUID == compared.objectUID)
  if(quantity == compared.quantity)
  if(objectPrice == compared.objectPrice)
  if(publicPrice == compared.publicPrice)
  if(_effectstree == compared._effectstree)
  return true;
  
  return false;
}

