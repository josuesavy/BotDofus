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
    if(this->objects[_i1] < 0)
    {
      qDebug()<<"ERREUR - FightLoot -"<<"Forbidden value (" << this->objects[_i1] << ") on element 1 (starting at 1) of objects.";
    }
    output->writeVarInt((int)this->objects[_i1]);
  }
  if(this->kamas < 0 || this->kamas > 9.007199254740992E15)
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
  uint _val1 = 0;
  uint _objectsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _objectsLen; _i1++)
  {
    _val1 = input->readVarUhInt();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - FightLoot -"<<"Forbidden value (" << _val1 << ") on elements of objects.";
    }
    this->objects.append(_val1);
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
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_objectstree.addChild(std::bind(&FightLoot::_objectsFunc, this, std::placeholders::_1));
  }
}

void FightLoot::_objectsFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - FightLoot -"<<"Forbidden value (" << _val << ") on elements of objects.";
  }
  this->objects.append(_val);
}

void FightLoot::_kamasFunc(Reader *input)
{
  this->kamas = input->readVarUhLong();
  if(this->kamas < 0 || this->kamas > 9.007199254740992E15)
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

