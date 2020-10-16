#include "FightResultPlayerListEntry.h"

void FightResultPlayerListEntry::serialize(Writer *output)
{
  this->serializeAs_FightResultPlayerListEntry(output);
}

void FightResultPlayerListEntry::serializeAs_FightResultPlayerListEntry(Writer *output)
{
  FightResultFighterListEntry::serializeAs_FightResultFighterListEntry(output);
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - FightResultPlayerListEntry -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  output->writeVarShort((int)this->level);
  output->writeShort((short)this->additional.size());
  for(uint _i2 = 0; _i2 < this->additional.size(); _i2++)
  {
    output->writeShort((short)qSharedPointerCast<FightResultAdditionalData>(this->additional[_i2])->getTypes().last());
    qSharedPointerCast<FightResultAdditionalData>(this->additional[_i2])->serialize(output);
  }
}

void FightResultPlayerListEntry::deserialize(Reader *input)
{
  this->deserializeAs_FightResultPlayerListEntry(input);
}

void FightResultPlayerListEntry::deserializeAs_FightResultPlayerListEntry(Reader *input)
{
  uint _id2 = 0;
  QSharedPointer<FightResultAdditionalData> _item2 ;
  FightResultFighterListEntry::deserialize(input);
  this->_levelFunc(input);
  uint _additionalLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _additionalLen; _i2++)
  {
    _id2 = input->readUShort();
    _item2 = qSharedPointerCast<FightResultAdditionalData>(ClassManagerSingleton::get()->getClass(_id2));
    _item2->deserialize(input);
    this->additional.append(_item2);
  }
}

void FightResultPlayerListEntry::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightResultPlayerListEntry(tree);
}

void FightResultPlayerListEntry::deserializeAsyncAs_FightResultPlayerListEntry(FuncTree tree)
{
  FightResultFighterListEntry::deserializeAsync(tree);
  tree.addChild(std::bind(&FightResultPlayerListEntry::_levelFunc, this, std::placeholders::_1));
  this->_additionaltree = tree.addChild(std::bind(&FightResultPlayerListEntry::_additionaltreeFunc, this, std::placeholders::_1));
}

void FightResultPlayerListEntry::_levelFunc(Reader *input)
{
  this->level = input->readVarUhShort();
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - FightResultPlayerListEntry -"<<"Forbidden value (" << this->level << ") on element of FightResultPlayerListEntry.level.";
  }
}

void FightResultPlayerListEntry::_additionaltreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_additionaltree.addChild(std::bind(&FightResultPlayerListEntry::_additionalFunc, this, std::placeholders::_1));
  }
}

void FightResultPlayerListEntry::_additionalFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<FightResultAdditionalData> _item = qSharedPointerCast<FightResultAdditionalData>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->additional.append(_item);
}

FightResultPlayerListEntry::FightResultPlayerListEntry()
{
  m_types<<ClassEnum::FIGHTRESULTPLAYERLISTENTRY;
}

bool FightResultPlayerListEntry::operator==(const FightResultPlayerListEntry &compared)
{
  if(level == compared.level)
  if(additional == compared.additional)
  if(_additionaltree == compared._additionaltree)
  return true;
  
  return false;
}

