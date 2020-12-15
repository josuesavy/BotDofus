#include "BreachReward.h"

void BreachReward::serialize(Writer *output)
{
  this->serializeAs_BreachReward(output);
}

void BreachReward::serializeAs_BreachReward(Writer *output)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - BreachReward -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarInt((int)this->id);
  output->writeShort((short)this->buyLocks.size());
  for(uint _i2 = 0; _i2 < this->buyLocks.size(); _i2++)
  {
    output->writeByte(this->buyLocks[_i2]);
  }
  output->writeUTF(this->buyCriterion);
  output->writeVarInt((int)this->remainingQty);
  if(this->price < 0)
  {
    qDebug()<<"ERREUR - BreachReward -"<<"Forbidden value (" << this->price << ") on element price.";
  }
  output->writeVarInt((int)this->price);
}

void BreachReward::deserialize(Reader *input)
{
  this->deserializeAs_BreachReward(input);
}

void BreachReward::deserializeAs_BreachReward(Reader *input)
{
  uint _val2 = 0;
  this->_idFunc(input);
  uint _buyLocksLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _buyLocksLen; _i2++)
  {
    _val2 = input->readByte();
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - BreachReward -"<<"Forbidden value (" << _val2 << ") on elements of buyLocks.";
    }
    this->buyLocks.append(_val2);
  }
  this->_buyCriterionFunc(input);
  this->_remainingQtyFunc(input);
  this->_priceFunc(input);
}

void BreachReward::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BreachReward(tree);
}

void BreachReward::deserializeAsyncAs_BreachReward(FuncTree tree)
{
  tree.addChild(std::bind(&BreachReward::_idFunc, this, std::placeholders::_1));
  this->_buyLockstree = tree.addChild(std::bind(&BreachReward::_buyLockstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BreachReward::_buyCriterionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BreachReward::_remainingQtyFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BreachReward::_priceFunc, this, std::placeholders::_1));
}

void BreachReward::_idFunc(Reader *input)
{
  this->id = input->readVarUhInt();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - BreachReward -"<<"Forbidden value (" << this->id << ") on element of BreachReward.id.";
  }
}

void BreachReward::_buyLockstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_buyLockstree.addChild(std::bind(&BreachReward::_buyLocksFunc, this, std::placeholders::_1));
  }
}

void BreachReward::_buyLocksFunc(Reader *input)
{
  uint _val = input->readByte();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - BreachReward -"<<"Forbidden value (" << _val << ") on elements of buyLocks.";
  }
  this->buyLocks.append(_val);
}

void BreachReward::_buyCriterionFunc(Reader *input)
{
  this->buyCriterion = input->readUTF();
}

void BreachReward::_remainingQtyFunc(Reader *input)
{
  this->remainingQty = input->readVarInt();
}

void BreachReward::_priceFunc(Reader *input)
{
  this->price = input->readVarUhInt();
  if(this->price < 0)
  {
    qDebug()<<"ERREUR - BreachReward -"<<"Forbidden value (" << this->price << ") on element of BreachReward.price.";
  }
}

BreachReward::BreachReward()
{
  m_types<<ClassEnum::BREACHREWARD;
}

bool BreachReward::operator==(const BreachReward &compared)
{
  if(id == compared.id)
  if(buyLocks == compared.buyLocks)
  if(buyCriterion == compared.buyCriterion)
  if(remainingQty == compared.remainingQty)
  if(price == compared.price)
  if(_buyLockstree == compared._buyLockstree)
  return true;
  
  return false;
}

