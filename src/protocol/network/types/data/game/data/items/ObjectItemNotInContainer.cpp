#include "ObjectItemNotInContainer.h"

void ObjectItemNotInContainer::serialize(Writer *output)
{
  this->serializeAs_ObjectItemNotInContainer(output);
}

void ObjectItemNotInContainer::serializeAs_ObjectItemNotInContainer(Writer *output)
{
  Item::serializeAs_Item(output);
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemNotInContainer -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
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
    qDebug()<<"ERREUR - ObjectItemNotInContainer -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  output->writeVarInt((int)this->objectUID);
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectItemNotInContainer -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
  }
  output->writeVarInt((int)this->quantity);
}

void ObjectItemNotInContainer::deserialize(Reader *input)
{
  this->deserializeAs_ObjectItemNotInContainer(input);
}

void ObjectItemNotInContainer::deserializeAs_ObjectItemNotInContainer(Reader *input)
{
  uint _id2 = 0;
  QSharedPointer<ObjectEffect> _item2 ;
  Item::deserialize(input);
  this->_objectGIDFunc(input);
  uint _effectsLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _effectsLen; _i2++)
  {
    _id2 = uint(input->readUShort());
    _item2 = qSharedPointerCast<ObjectEffect>(ClassManagerSingleton::get()->getClass(_id2));
    _item2->deserialize(input);
    this->effects.append(_item2);
  }
  this->_objectUIDFunc(input);
  this->_quantityFunc(input);
}

void ObjectItemNotInContainer::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectItemNotInContainer(tree);
}

void ObjectItemNotInContainer::deserializeAsyncAs_ObjectItemNotInContainer(FuncTree tree)
{
  Item::deserializeAsync(tree);
  tree.addChild(std::bind(&ObjectItemNotInContainer::_objectGIDFunc, this, std::placeholders::_1));
  this->_effectstree = tree.addChild(std::bind(&ObjectItemNotInContainer::_effectstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectItemNotInContainer::_objectUIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectItemNotInContainer::_quantityFunc, this, std::placeholders::_1));
}

void ObjectItemNotInContainer::_objectGIDFunc(Reader *input)
{
  this->objectGID = input->readVarUhInt();
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemNotInContainer -"<<"Forbidden value (" << this->objectGID << ") on element of ObjectItemNotInContainer.objectGID.";
  }
}

void ObjectItemNotInContainer::_effectstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_effectstree.addChild(std::bind(&ObjectItemNotInContainer::_effectsFunc, this, std::placeholders::_1));
  }
}

void ObjectItemNotInContainer::_effectsFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<ObjectEffect> _item = qSharedPointerCast<ObjectEffect>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->effects.append(_item);
}

void ObjectItemNotInContainer::_objectUIDFunc(Reader *input)
{
  this->objectUID = input->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemNotInContainer -"<<"Forbidden value (" << this->objectUID << ") on element of ObjectItemNotInContainer.objectUID.";
  }
}

void ObjectItemNotInContainer::_quantityFunc(Reader *input)
{
  this->quantity = input->readVarUhInt();
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectItemNotInContainer -"<<"Forbidden value (" << this->quantity << ") on element of ObjectItemNotInContainer.quantity.";
  }
}

ObjectItemNotInContainer::ObjectItemNotInContainer()
{
  m_types<<ClassEnum::OBJECTITEMNOTINCONTAINER;
}

bool ObjectItemNotInContainer::operator==(const ObjectItemNotInContainer &compared)
{
  if(objectGID == compared.objectGID)
  if(effects == compared.effects)
  if(objectUID == compared.objectUID)
  if(quantity == compared.quantity)
  if(_effectstree == compared._effectstree)
  return true;
  
  return false;
}

