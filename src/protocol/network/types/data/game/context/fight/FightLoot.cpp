#include "FightLoot.h"

void FightLoot::serialize(Writer *output)
{
  this->serializeAs_FightLoot(output);
}

void FightLoot::serializeAs_FightLoot(Writer *output)
{
  output->writeShort((short)this->objects.size());
  for(uint _i1 = 0; _i1 < this->objects.size(); _i1++)
  {
    (this->objects[_i1]).serializeAs_FightLootObject(output);
  }
  if(this->kamas < 0 || this->kamas > 9007199254740992)
  {
    qDebug()<<"ERREUR - FightLoot -"<<"Forbidden value (" << this->kamas << ") on element kamas.";
  }
  output->writeVarLong((double)this->kamas);
}

void FightLoot::deserialize(Reader *input)
{
  this->deserializeAs_FightLoot(input);
}

void FightLoot::deserializeAs_FightLoot(Reader *input)
{
  FightLootObject _item1 ;
  uint _objectsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _objectsLen; _i1++)
  {
    _item1 = FightLootObject();
    _item1.deserialize(input);
    this->objects.append(_item1);
  }
  this->_kamasFunc(input);
}

void FightLoot::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightLoot(tree);
}

void FightLoot::deserializeAsyncAs_FightLoot(FuncTree tree)
{
  this->_objectstree = tree.addChild(std::bind(&FightLoot::_objectstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightLoot::_kamasFunc, this, std::placeholders::_1));
}

void FightLoot::_objectstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_objectstree.addChild(std::bind(&FightLoot::_objectsFunc, this, std::placeholders::_1));
  }
}

void FightLoot::_objectsFunc(Reader *input)
{
  FightLootObject _item = FightLootObject();
  _item.deserialize(input);
  this->objects.append(_item);
}

void FightLoot::_kamasFunc(Reader *input)
{
  this->kamas = input->readVarUhLong();
  if(this->kamas < 0 || this->kamas > 9007199254740992)
  {
    qDebug()<<"ERREUR - FightLoot -"<<"Forbidden value (" << this->kamas << ") on element of FightLoot.kamas.";
  }
}

FightLoot::FightLoot()
{
  m_types<<ClassEnum::FIGHTLOOT;
}

bool FightLoot::operator==(const FightLoot &compared)
{
  if(objects == compared.objects)
  if(kamas == compared.kamas)
  if(_objectstree == compared._objectstree)
  return true;
  
  return false;
}

