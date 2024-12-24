#include "MonsterBoosts.h"

void MonsterBoosts::serialize(Writer *output)
{
  this->serializeAs_MonsterBoosts(output);
}

void MonsterBoosts::serializeAs_MonsterBoosts(Writer *output)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - MonsterBoosts -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarInt((int)this->id);
  if(this->xpBoost < 0)
  {
    qDebug()<<"ERREUR - MonsterBoosts -"<<"Forbidden value (" << this->xpBoost << ") on element xpBoost.";
  }
  output->writeVarShort((int)this->xpBoost);
  if(this->dropBoost < 0)
  {
    qDebug()<<"ERREUR - MonsterBoosts -"<<"Forbidden value (" << this->dropBoost << ") on element dropBoost.";
  }
  output->writeVarShort((int)this->dropBoost);
}

void MonsterBoosts::deserialize(Reader *input)
{
  this->deserializeAs_MonsterBoosts(input);
}

void MonsterBoosts::deserializeAs_MonsterBoosts(Reader *input)
{
  this->_idFunc(input);
  this->_xpBoostFunc(input);
  this->_dropBoostFunc(input);
}

void MonsterBoosts::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MonsterBoosts(tree);
}

void MonsterBoosts::deserializeAsyncAs_MonsterBoosts(FuncTree tree)
{
  tree.addChild(std::bind(&MonsterBoosts::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MonsterBoosts::_xpBoostFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MonsterBoosts::_dropBoostFunc, this, std::placeholders::_1));
}

void MonsterBoosts::_idFunc(Reader *input)
{
  this->id = input->readVarUhInt();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - MonsterBoosts -"<<"Forbidden value (" << this->id << ") on element of MonsterBoosts.id.";
  }
}

void MonsterBoosts::_xpBoostFunc(Reader *input)
{
  this->xpBoost = input->readVarUhShort();
  if(this->xpBoost < 0)
  {
    qDebug()<<"ERREUR - MonsterBoosts -"<<"Forbidden value (" << this->xpBoost << ") on element of MonsterBoosts.xpBoost.";
  }
}

void MonsterBoosts::_dropBoostFunc(Reader *input)
{
  this->dropBoost = input->readVarUhShort();
  if(this->dropBoost < 0)
  {
    qDebug()<<"ERREUR - MonsterBoosts -"<<"Forbidden value (" << this->dropBoost << ") on element of MonsterBoosts.dropBoost.";
  }
}

MonsterBoosts::MonsterBoosts()
{
  m_types<<ClassEnum::MONSTERBOOSTS;
}

bool MonsterBoosts::operator==(const MonsterBoosts &compared)
{
  if(id == compared.id)
  if(xpBoost == compared.xpBoost)
  if(dropBoost == compared.dropBoost)
  return true;
  
  return false;
}

