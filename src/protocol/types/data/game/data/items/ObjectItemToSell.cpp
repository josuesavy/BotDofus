#include "ObjectItemToSell.h"

void ObjectItemToSell::serialize(Writer *output)
{
  this->serializeAs_ObjectItemToSell(output);
}

void ObjectItemToSell::serializeAs_ObjectItemToSell(Writer *output)
{
  Item::serializeAs_Item(output);
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemToSell -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
  }
  output->writeVarInt((int)this->objectGID);
  output->writeShort((short)this->effects.size());
  for(uint _i2 = 0; _i2 < this->effects.size(); _i2++)
  {
    output->writeShort((short)qSharedPointerCast<ObjectEffect>(this->effects[_i2])->getTypes().last());
    qSharedPointerCast<ObjectEffect>(this->effects[_i2])->serialize(output);
  }
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemToSell -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  output->writeVarInt((int)this->objectUID);
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectItemToSell -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
  }
  output->writeVarInt((int)this->quantity);
  if(this->objectPrice < 0 || this->objectPrice > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ObjectItemToSell -"<<"Forbidden value (" << this->objectPrice << ") on element objectPrice.";
  }
  output->writeVarLong((double)this->objectPrice);
}

void ObjectItemToSell::deserialize(Reader *input)
{
  this->deserializeAs_ObjectItemToSell(input);
}

void ObjectItemToSell::deserializeAs_ObjectItemToSell(Reader *input)
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
}

void ObjectItemToSell::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectItemToSell(tree);
}

void ObjectItemToSell::deserializeAsyncAs_ObjectItemToSell(FuncTree tree)
{
  Item::deserializeAsync(tree);
  tree.addChild(std::bind(&ObjectItemToSell::_objectGIDFunc, this, std::placeholders::_1));
  this->_effectstree = tree.addChild(std::bind(&ObjectItemToSell::_effectstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectItemToSell::_objectUIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectItemToSell::_quantityFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectItemToSell::_objectPriceFunc, this, std::placeholders::_1));
}

void ObjectItemToSell::_objectGIDFunc(Reader *input)
{
  this->objectGID = input->readVarUhInt();
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemToSell -"<<"Forbidden value (" << this->objectGID << ") on element of ObjectItemToSell.objectGID.";
  }
}

void ObjectItemToSell::_effectstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_effectstree.addChild(std::bind(&ObjectItemToSell::_effectsFunc, this, std::placeholders::_1));
  }
}

void ObjectItemToSell::_effectsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<ObjectEffect> _item = qSharedPointerCast<ObjectEffect>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->effects.append(_item);
}

void ObjectItemToSell::_objectUIDFunc(Reader *input)
{
  this->objectUID = input->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemToSell -"<<"Forbidden value (" << this->objectUID << ") on element of ObjectItemToSell.objectUID.";
  }
}

void ObjectItemToSell::_quantityFunc(Reader *input)
{
  this->quantity = input->readVarUhInt();
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectItemToSell -"<<"Forbidden value (" << this->quantity << ") on element of ObjectItemToSell.quantity.";
  }
}

void ObjectItemToSell::_objectPriceFunc(Reader *input)
{
  this->objectPrice = input->readVarUhLong();
  if(this->objectPrice < 0 || this->objectPrice > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ObjectItemToSell -"<<"Forbidden value (" << this->objectPrice << ") on element of ObjectItemToSell.objectPrice.";
  }
}

ObjectItemToSell::ObjectItemToSell()
{
  m_types<<ClassEnum::OBJECTITEMTOSELL;
}

bool ObjectItemToSell::operator==(const ObjectItemToSell &compared)
{
  if(objectGID == compared.objectGID)
  if(effects == compared.effects)
  if(objectUID == compared.objectUID)
  if(quantity == compared.quantity)
  if(objectPrice == compared.objectPrice)
  if(_effectstree == compared._effectstree)
  return true;
  
  return false;
}

