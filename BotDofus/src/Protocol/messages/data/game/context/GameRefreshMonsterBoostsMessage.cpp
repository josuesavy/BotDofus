#include "GameRefreshMonsterBoostsMessage.h"

void GameRefreshMonsterBoostsMessage::serialize(Writer *output)
{
  this->serializeAs_GameRefreshMonsterBoostsMessage(output);
}

void GameRefreshMonsterBoostsMessage::serializeAs_GameRefreshMonsterBoostsMessage(Writer *output)
{
  output->writeShort((short)this->monsterBoosts.size());
  for(uint _i1 = 0; _i1 < this->monsterBoosts.size(); _i1++)
  {
    (this->monsterBoosts[_i1]).serializeAs_MonsterBoosts(output);
  }
  output->writeShort((short)this->familyBoosts.size());
  for(uint _i2 = 0; _i2 < this->familyBoosts.size(); _i2++)
  {
    (this->familyBoosts[_i2]).serializeAs_MonsterBoosts(output);
  }
}

void GameRefreshMonsterBoostsMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRefreshMonsterBoostsMessage(input);
}

void GameRefreshMonsterBoostsMessage::deserializeAs_GameRefreshMonsterBoostsMessage(Reader *input)
{
  MonsterBoosts _item1 ;
  MonsterBoosts _item2 ;
  uint _monsterBoostsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _monsterBoostsLen; _i1++)
  {
    _item1 = MonsterBoosts();
    _item1.deserialize(input);
    this->monsterBoosts.append(_item1);
  }
  uint _familyBoostsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _familyBoostsLen; _i2++)
  {
    _item2 = MonsterBoosts();
    _item2.deserialize(input);
    this->familyBoosts.append(_item2);
  }
}

void GameRefreshMonsterBoostsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRefreshMonsterBoostsMessage(tree);
}

void GameRefreshMonsterBoostsMessage::deserializeAsyncAs_GameRefreshMonsterBoostsMessage(FuncTree tree)
{
  this->_monsterBooststree = tree.addChild(std::bind(&GameRefreshMonsterBoostsMessage::_monsterBooststreeFunc, this, std::placeholders::_1));
  this->_familyBooststree = tree.addChild(std::bind(&GameRefreshMonsterBoostsMessage::_familyBooststreeFunc, this, std::placeholders::_1));
}

void GameRefreshMonsterBoostsMessage::_monsterBooststreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_monsterBooststree.addChild(std::bind(&GameRefreshMonsterBoostsMessage::_monsterBoostsFunc, this, std::placeholders::_1));
  }
}

void GameRefreshMonsterBoostsMessage::_monsterBoostsFunc(Reader *input)
{
  MonsterBoosts _item = MonsterBoosts();
  _item.deserialize(input);
  this->monsterBoosts.append(_item);
}

void GameRefreshMonsterBoostsMessage::_familyBooststreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_familyBooststree.addChild(std::bind(&GameRefreshMonsterBoostsMessage::_familyBoostsFunc, this, std::placeholders::_1));
  }
}

void GameRefreshMonsterBoostsMessage::_familyBoostsFunc(Reader *input)
{
  MonsterBoosts _item = MonsterBoosts();
  _item.deserialize(input);
  this->familyBoosts.append(_item);
}

GameRefreshMonsterBoostsMessage::GameRefreshMonsterBoostsMessage()
{
  m_type = MessageEnum::GAMEREFRESHMONSTERBOOSTSMESSAGE;
}

