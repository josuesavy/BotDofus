#include "GameRolePlayNpcQuestFlag.h"

void GameRolePlayNpcQuestFlag::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayNpcQuestFlag(output);
}

void GameRolePlayNpcQuestFlag::serializeAs_GameRolePlayNpcQuestFlag(Writer *output)
{
  output->writeShort((short)this->questsToValidId.size());
  for(uint _i1 = 0; _i1 < this->questsToValidId.size(); _i1++)
  {
    if(this->questsToValidId[_i1] < 0)
    {
      qDebug()<<"ERREUR - GameRolePlayNpcQuestFlag -"<<"Forbidden value (" << this->questsToValidId[_i1] << ") on element 1 (starting at 1) of questsToValidId.";
    }
    output->writeVarShort((int)this->questsToValidId[_i1]);
  }
  output->writeShort((short)this->questsToStartId.size());
  for(uint _i2 = 0; _i2 < this->questsToStartId.size(); _i2++)
  {
    if(this->questsToStartId[_i2] < 0)
    {
      qDebug()<<"ERREUR - GameRolePlayNpcQuestFlag -"<<"Forbidden value (" << this->questsToStartId[_i2] << ") on element 2 (starting at 1) of questsToStartId.";
    }
    output->writeVarShort((int)this->questsToStartId[_i2]);
  }
}

void GameRolePlayNpcQuestFlag::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayNpcQuestFlag(input);
}

void GameRolePlayNpcQuestFlag::deserializeAs_GameRolePlayNpcQuestFlag(Reader *input)
{
  uint _val1 = 0;
  uint _val2 = 0;
  uint _questsToValidIdLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _questsToValidIdLen; _i1++)
  {
    _val1 = input->readVarUhShort();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - GameRolePlayNpcQuestFlag -"<<"Forbidden value (" << _val1 << ") on elements of questsToValidId.";
    }
    this->questsToValidId.append(_val1);
  }
  uint _questsToStartIdLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _questsToStartIdLen; _i2++)
  {
    _val2 = input->readVarUhShort();
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - GameRolePlayNpcQuestFlag -"<<"Forbidden value (" << _val2 << ") on elements of questsToStartId.";
    }
    this->questsToStartId.append(_val2);
  }
}

void GameRolePlayNpcQuestFlag::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayNpcQuestFlag(tree);
}

void GameRolePlayNpcQuestFlag::deserializeAsyncAs_GameRolePlayNpcQuestFlag(FuncTree tree)
{
  this->_questsToValidIdtree = tree.addChild(std::bind(&GameRolePlayNpcQuestFlag::_questsToValidIdtreeFunc, this, std::placeholders::_1));
  this->_questsToStartIdtree = tree.addChild(std::bind(&GameRolePlayNpcQuestFlag::_questsToStartIdtreeFunc, this, std::placeholders::_1));
}

void GameRolePlayNpcQuestFlag::_questsToValidIdtreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_questsToValidIdtree.addChild(std::bind(&GameRolePlayNpcQuestFlag::_questsToValidIdFunc, this, std::placeholders::_1));
  }
}

void GameRolePlayNpcQuestFlag::_questsToValidIdFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayNpcQuestFlag -"<<"Forbidden value (" << _val << ") on elements of questsToValidId.";
  }
  this->questsToValidId.append(_val);
}

void GameRolePlayNpcQuestFlag::_questsToStartIdtreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_questsToStartIdtree.addChild(std::bind(&GameRolePlayNpcQuestFlag::_questsToStartIdFunc, this, std::placeholders::_1));
  }
}

void GameRolePlayNpcQuestFlag::_questsToStartIdFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayNpcQuestFlag -"<<"Forbidden value (" << _val << ") on elements of questsToStartId.";
  }
  this->questsToStartId.append(_val);
}

GameRolePlayNpcQuestFlag::GameRolePlayNpcQuestFlag()
{
  m_types<<ClassEnum::GAMEROLEPLAYNPCQUESTFLAG;
}

bool GameRolePlayNpcQuestFlag::operator==(const GameRolePlayNpcQuestFlag &compared)
{
  if(questsToValidId == compared.questsToValidId)
  if(questsToStartId == compared.questsToStartId)
  if(_questsToValidIdtree == compared._questsToValidIdtree)
  if(_questsToStartIdtree == compared._questsToStartIdtree)
  return true;
  
  return false;
}

