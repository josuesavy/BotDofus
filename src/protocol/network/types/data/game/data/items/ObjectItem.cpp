#include "ObjectItem.h"

void ObjectItem::serialize(Writer *output)
{
  this->serializeAs_ObjectItem(output);
}

void ObjectItem::serializeAs_ObjectItem(Writer *output)
{
  Item::serializeAs_Item(output);
  output->writeShort((short)this->position);
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ObjectItem -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
  }
  output->writeVarInt((int)this->objectGID);
  output->writeShort((short)this->effects.size());
  for(uint _i3 = 0; _i3 < this->effects.size(); _i3++)
  {
    output->writeShort((short)qSharedPointerCast<ObjectEffect>(this->effects[_i3])->getTypes().last());
    qSharedPointerCast<ObjectEffect>(this->effects[_i3])->serialize(output);
  }
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectItem -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  output->writeVarInt((int)this->objectUID);
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectItem -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
  }
  output->writeVarInt((int)this->quantity);
}

void ObjectItem::deserialize(Reader *input)
{
  this->deserializeAs_ObjectItem(input);
}

void ObjectItem::deserializeAs_ObjectItem(Reader *input)
{
  uint _id3 = 0;
  QSharedPointer<ObjectEffect> _item3 ;
  Item::deserialize(input);
  this->_positionFunc(input);
  this->_objectGIDFunc(input);
  uint _effectsLen = uint(input->readUShort());
  for(uint _i3 = 0; _i3 < _effectsLen; _i3++)
  {
    _id3 = uint(input->readUShort());
    _item3 = qSharedPointerCast<ObjectEffect>(ClassManagerSingleton::get()->getClass(_id3));
    _item3->deserialize(input);
    this->effects.append(_item3);
  }
  this->_objectUIDFunc(input);
  this->_quantityFunc(input);
}

void ObjectItem::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectItem(tree);
}

void ObjectItem::deserializeAsyncAs_ObjectItem(FuncTree tree)
{
  Item::deserializeAsync(tree);
  tree.addChild(std::bind(&ObjectItem::_positionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectItem::_objectGIDFunc, this, std::placeholders::_1));
  this->_effectstree = tree.addChild(std::bind(&ObjectItem::_effectstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectItem::_objectUIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectItem::_quantityFunc, this, std::placeholders::_1));
}

void ObjectItem::_positionFunc(Reader *input)
{
  this->position = input->readShort();
  if(this->position < 0)
  {
    qDebug()<<"ERREUR - ObjectItem -"<<"Forbidden value (" << this->position << ") on element of ObjectItem.position.";
  }
}

void ObjectItem::_objectGIDFunc(Reader *input)
{
  this->objectGID = input->readVarUhInt();
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ObjectItem -"<<"Forbidden value (" << this->objectGID << ") on element of ObjectItem.objectGID.";
  }
}

void ObjectItem::_effectstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_effectstree.addChild(std::bind(&ObjectItem::_effectsFunc, this, std::placeholders::_1));
  }
}

void ObjectItem::_effectsFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<ObjectEffect> _item = qSharedPointerCast<ObjectEffect>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->effects.append(_item);
}

void ObjectItem::_objectUIDFunc(Reader *input)
{
  this->objectUID = input->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectItem -"<<"Forbidden value (" << this->objectUID << ") on element of ObjectItem.objectUID.";
  }
}

void ObjectItem::_quantityFunc(Reader *input)
{
  this->quantity = input->readVarUhInt();
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectItem -"<<"Forbidden value (" << this->quantity << ") on element of ObjectItem.quantity.";
  }
}

ObjectItem::ObjectItem()
{
  m_types<<ClassEnum::OBJECTITEM;
}

bool ObjectItem::operator==(const ObjectItem &compared)
{
  if(position == compared.position)
  if(objectGID == compared.objectGID)
  if(effects == compared.effects)
  if(objectUID == compared.objectUID)
  if(quantity == compared.quantity)
  if(_effectstree == compared._effectstree)
  return true;
  
  return false;
}

