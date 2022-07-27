#include "GameRolePlayArenaFightPropositionMessage.h"

void GameRolePlayArenaFightPropositionMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayArenaFightPropositionMessage(output);
}

void GameRolePlayArenaFightPropositionMessage::serializeAs_GameRolePlayArenaFightPropositionMessage(Writer *output)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaFightPropositionMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeVarShort((int)this->fightId);
  output->writeShort((short)this->alliesId.size());
  for(uint _i2 = 0; _i2 < this->alliesId.size(); _i2++)
  {
    if(this->alliesId[_i2] < -9.007199254740992E15 || this->alliesId[_i2] > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameRolePlayArenaFightPropositionMessage -"<<"Forbidden value (" << this->alliesId[_i2] << ") on element 2 (starting at 1) of alliesId.";
    }
    output->writeDouble(this->alliesId[_i2]);
  }
  if(this->duration < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaFightPropositionMessage -"<<"Forbidden value (" << this->duration << ") on element duration.";
  }
  output->writeVarShort((int)this->duration);
}

void GameRolePlayArenaFightPropositionMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayArenaFightPropositionMessage(input);
}

void GameRolePlayArenaFightPropositionMessage::deserializeAs_GameRolePlayArenaFightPropositionMessage(Reader *input)
{
  auto _val2 = NULL;
  this->_fightIdFunc(input);
  uint _alliesIdLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _alliesIdLen; _i2++)
  {
    _val2 = input->readDouble();
    if(_val2 < -9.007199254740992E15 || _val2 > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameRolePlayArenaFightPropositionMessage -"<<"Forbidden value (" << _val2 << ") on elements of alliesId.";
    }
    this->alliesId.append(_val2);
  }
  this->_durationFunc(input);
}

void GameRolePlayArenaFightPropositionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayArenaFightPropositionMessage(tree);
}

void GameRolePlayArenaFightPropositionMessage::deserializeAsyncAs_GameRolePlayArenaFightPropositionMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameRolePlayArenaFightPropositionMessage::_fightIdFunc, this, std::placeholders::_1));
  this->_alliesIdtree = tree.addChild(std::bind(&GameRolePlayArenaFightPropositionMessage::_alliesIdtreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayArenaFightPropositionMessage::_durationFunc, this, std::placeholders::_1));
}

void GameRolePlayArenaFightPropositionMessage::_fightIdFunc(Reader *input)
{
  this->fightId = input->readVarUhShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaFightPropositionMessage -"<<"Forbidden value (" << this->fightId << ") on element of GameRolePlayArenaFightPropositionMessage.fightId.";
  }
}

void GameRolePlayArenaFightPropositionMessage::_alliesIdtreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_alliesIdtree.addChild(std::bind(&GameRolePlayArenaFightPropositionMessage::_alliesIdFunc, this, std::placeholders::_1));
  }
}

void GameRolePlayArenaFightPropositionMessage::_alliesIdFunc(Reader *input)
{
  double _val = input->readDouble();
  if(_val < -9.007199254740992E15 || _val > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaFightPropositionMessage -"<<"Forbidden value (" << _val << ") on elements of alliesId.";
  }
  this->alliesId.append(_val);
}

void GameRolePlayArenaFightPropositionMessage::_durationFunc(Reader *input)
{
  this->duration = input->readVarUhShort();
  if(this->duration < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaFightPropositionMessage -"<<"Forbidden value (" << this->duration << ") on element of GameRolePlayArenaFightPropositionMessage.duration.";
  }
}

GameRolePlayArenaFightPropositionMessage::GameRolePlayArenaFightPropositionMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYARENAFIGHTPROPOSITIONMESSAGE;
}

