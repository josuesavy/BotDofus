#include "ObjectItemMinimalInformation.h"

void ObjectItemMinimalInformation::serialize(Writer *output)
{
  this->serializeAs_ObjectItemMinimalInformation(output);
}

void ObjectItemMinimalInformation::serializeAs_ObjectItemMinimalInformation(Writer *output)
{
  Item::serializeAs_Item(output);
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemMinimalInformation -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
  }
  output->writeVarInt((int)this->objectGID);
  output->writeShort((short)this->effects.size());
  for(uint _i2 = 0; _i2 < this->effects.size(); _i2++)
  {
    output->writeShort((short)qSharedPointerCast<ObjectEffect>(this->effects[_i2])->getTypes().last());
    qSharedPointerCast<ObjectEffect>(this->effects[_i2])->serialize(output);
  }
}

void ObjectItemMinimalInformation::deserialize(Reader *input)
{
  this->deserializeAs_ObjectItemMinimalInformation(input);
}

void ObjectItemMinimalInformation::deserializeAs_ObjectItemMinimalInformation(Reader *input)
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
}

void ObjectItemMinimalInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectItemMinimalInformation(tree);
}

void ObjectItemMinimalInformation::deserializeAsyncAs_ObjectItemMinimalInformation(FuncTree tree)
{
  Item::deserializeAsync(tree);
  tree.addChild(std::bind(&ObjectItemMinimalInformation::_objectGIDFunc, this, std::placeholders::_1));
  this->_effectstree = tree.addChild(std::bind(&ObjectItemMinimalInformation::_effectstreeFunc, this, std::placeholders::_1));
}

void ObjectItemMinimalInformation::_objectGIDFunc(Reader *input)
{
  this->objectGID = input->readVarUhInt();
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemMinimalInformation -"<<"Forbidden value (" << this->objectGID << ") on element of ObjectItemMinimalInformation.objectGID.";
  }
}

void ObjectItemMinimalInformation::_effectstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_effectstree.addChild(std::bind(&ObjectItemMinimalInformation::_effectsFunc, this, std::placeholders::_1));
  }
}

void ObjectItemMinimalInformation::_effectsFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<ObjectEffect> _item = qSharedPointerCast<ObjectEffect>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->effects.append(_item);
}

ObjectItemMinimalInformation::ObjectItemMinimalInformation()
{
  m_types<<ClassEnum::OBJECTITEMMINIMALINFORMATION;
}

bool ObjectItemMinimalInformation::operator==(const ObjectItemMinimalInformation &compared)
{
  if(objectGID == compared.objectGID)
  if(effects == compared.effects)
  if(_effectstree == compared._effectstree)
  return true;
  
  return false;
}

