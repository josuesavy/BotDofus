#include "ObjectEffects.h"

void ObjectEffects::serialize(Writer *output)
{
  this->serializeAs_ObjectEffects(output);
}

void ObjectEffects::serializeAs_ObjectEffects(Writer *output)
{
  output->writeShort((short)this->effects.size());
  for(uint _i1 = 0; _i1 < this->effects.size(); _i1++)
  {
    output->writeShort((short)qSharedPointerCast<ObjectEffect>(this->effects[_i1])->getTypes().last());
    qSharedPointerCast<ObjectEffect>(this->effects[_i1])->serialize(output);
  }
}

void ObjectEffects::deserialize(Reader *input)
{
  this->deserializeAs_ObjectEffects(input);
}

void ObjectEffects::deserializeAs_ObjectEffects(Reader *input)
{
  uint _id1 = 0;
  QSharedPointer<ObjectEffect> _item1 ;
  uint _effectsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _effectsLen; _i1++)
  {
    _id1 = input->readUShort();
    _item1 = qSharedPointerCast<ObjectEffect>(ClassManagerSingleton::get()->getClass(_id1));
    _item1->deserialize(input);
    this->effects.append(_item1);
  }
}

void ObjectEffects::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectEffects(tree);
}

void ObjectEffects::deserializeAsyncAs_ObjectEffects(FuncTree tree)
{
  this->_effectstree = tree.addChild(std::bind(&ObjectEffects::_effectstreeFunc, this, std::placeholders::_1));
}

void ObjectEffects::_effectstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_effectstree.addChild(std::bind(&ObjectEffects::_effectsFunc, this, std::placeholders::_1));
  }
}

void ObjectEffects::_effectsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<ObjectEffect> _item = qSharedPointerCast<ObjectEffect>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->effects.append(_item);
}

ObjectEffects::ObjectEffects()
{
  m_types<<ClassEnum::OBJECTEFFECTS;
}

bool ObjectEffects::operator==(const ObjectEffects &compared)
{
  if(effects == compared.effects)
  if(_effectstree == compared._effectstree)
  return true;
  
  return false;
}

