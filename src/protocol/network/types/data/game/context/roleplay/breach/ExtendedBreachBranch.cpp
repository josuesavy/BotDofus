#include "ExtendedBreachBranch.h"

void ExtendedBreachBranch::serialize(Writer *output)
{
  this->serializeAs_ExtendedBreachBranch(output);
}

void ExtendedBreachBranch::serializeAs_ExtendedBreachBranch(Writer *output)
{
  BreachBranch::serializeAs_BreachBranch(output);
  output->writeShort((short)this->rewards.size());
  for(uint _i1 = 0; _i1 < this->rewards.size(); _i1++)
  {
    (this->rewards[_i1]).serializeAs_BreachReward(output);
  }
  output->writeVarInt((int)this->modifier);
  if(this->prize < 0)
  {
    qDebug()<<"ERREUR - ExtendedBreachBranch -"<<"Forbidden value (" << this->prize << ") on element prize.";
  }
  output->writeVarInt((int)this->prize);
}

void ExtendedBreachBranch::deserialize(Reader *input)
{
  this->deserializeAs_ExtendedBreachBranch(input);
}

void ExtendedBreachBranch::deserializeAs_ExtendedBreachBranch(Reader *input)
{
   _item1 ;
  BreachBranch::deserialize(input);
  uint _rewardsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _rewardsLen; _i1++)
  {
    _item1 = new com.ankamagames.dofus.network.types.game.context.roleplay.breach.BreachReward();
    _item1.deserialize(input);
    this->rewards.append(_item1);
  }
  this->_modifierFunc(input);
  this->_prizeFunc(input);
}

void ExtendedBreachBranch::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExtendedBreachBranch(tree);
}

void ExtendedBreachBranch::deserializeAsyncAs_ExtendedBreachBranch(FuncTree tree)
{
  BreachBranch::deserializeAsync(tree);
  this->_rewardstree = tree.addChild(std::bind(&ExtendedBreachBranch::_rewardstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExtendedBreachBranch::_modifierFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExtendedBreachBranch::_prizeFunc, this, std::placeholders::_1));
}

void ExtendedBreachBranch::_rewardstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_rewardstree.addChild(std::bind(&ExtendedBreachBranch::_rewardsFunc, this, std::placeholders::_1));
  }
}

void ExtendedBreachBranch::_rewardsFunc(Reader *input)
{
   _item = new com.ankamagames.dofus.network.types.game.context.roleplay.breach.BreachReward();
  _item.deserialize(input);
  this->rewards.append(_item);
}

void ExtendedBreachBranch::_modifierFunc(Reader *input)
{
  this->modifier = input->readVarInt();
}

void ExtendedBreachBranch::_prizeFunc(Reader *input)
{
  this->prize = input->readVarUhInt();
  if(this->prize < 0)
  {
    qDebug()<<"ERREUR - ExtendedBreachBranch -"<<"Forbidden value (" << this->prize << ") on element of ExtendedBreachBranch.prize.";
  }
}

ExtendedBreachBranch::ExtendedBreachBranch()
{
  m_types<<ClassEnum::EXTENDEDBREACHBRANCH;
}

bool ExtendedBreachBranch::operator==(const ExtendedBreachBranch &compared)
{
  if(rewards == compared.rewards)
  if(modifier == compared.modifier)
  if(prize == compared.prize)
  if(_rewardstree == compared._rewardstree)
  return true;
  
  return false;
}

