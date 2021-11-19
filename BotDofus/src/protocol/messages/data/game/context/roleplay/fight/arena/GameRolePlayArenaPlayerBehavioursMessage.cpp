#include "GameRolePlayArenaPlayerBehavioursMessage.h"

void GameRolePlayArenaPlayerBehavioursMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayArenaPlayerBehavioursMessage(output);
}

void GameRolePlayArenaPlayerBehavioursMessage::serializeAs_GameRolePlayArenaPlayerBehavioursMessage(Writer *output)
{
  output->writeShort((short)this->flags.size());
  for(uint _i1 = 0; _i1 < this->flags.size(); _i1++)
  {
    output->writeUTF(this->flags[_i1]);
  }
  output->writeShort((short)this->sanctions.size());
  for(uint _i2 = 0; _i2 < this->sanctions.size(); _i2++)
  {
    output->writeUTF(this->sanctions[_i2]);
  }
  if(this->banDuration < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaPlayerBehavioursMessage -"<<"Forbidden value (" << this->banDuration << ") on element banDuration.";
  }
  output->writeInt((int)this->banDuration);
}

void GameRolePlayArenaPlayerBehavioursMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayArenaPlayerBehavioursMessage(input);
}

void GameRolePlayArenaPlayerBehavioursMessage::deserializeAs_GameRolePlayArenaPlayerBehavioursMessage(Reader *input)
{
  QString _val1 ;
  QString _val2 ;
  uint _flagsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _flagsLen; _i1++)
  {
    _val1 = input->readUTF();
    this->flags.append(_val1);
  }
  uint _sanctionsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _sanctionsLen; _i2++)
  {
    _val2 = input->readUTF();
    this->sanctions.append(_val2);
  }
  this->_banDurationFunc(input);
}

void GameRolePlayArenaPlayerBehavioursMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayArenaPlayerBehavioursMessage(tree);
}

void GameRolePlayArenaPlayerBehavioursMessage::deserializeAsyncAs_GameRolePlayArenaPlayerBehavioursMessage(FuncTree tree)
{
  this->_flagstree = tree.addChild(std::bind(&GameRolePlayArenaPlayerBehavioursMessage::_flagstreeFunc, this, std::placeholders::_1));
  this->_sanctionstree = tree.addChild(std::bind(&GameRolePlayArenaPlayerBehavioursMessage::_sanctionstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayArenaPlayerBehavioursMessage::_banDurationFunc, this, std::placeholders::_1));
}

void GameRolePlayArenaPlayerBehavioursMessage::_flagstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_flagstree.addChild(std::bind(&GameRolePlayArenaPlayerBehavioursMessage::_flagsFunc, this, std::placeholders::_1));
  }
}

void GameRolePlayArenaPlayerBehavioursMessage::_flagsFunc(Reader *input)
{
  QString _val = input->readUTF();
  this->flags.append(_val);
}

void GameRolePlayArenaPlayerBehavioursMessage::_sanctionstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_sanctionstree.addChild(std::bind(&GameRolePlayArenaPlayerBehavioursMessage::_sanctionsFunc, this, std::placeholders::_1));
  }
}

void GameRolePlayArenaPlayerBehavioursMessage::_sanctionsFunc(Reader *input)
{
  QString _val = input->readUTF();
  this->sanctions.append(_val);
}

void GameRolePlayArenaPlayerBehavioursMessage::_banDurationFunc(Reader *input)
{
  this->banDuration = input->readInt();
  if(this->banDuration < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaPlayerBehavioursMessage -"<<"Forbidden value (" << this->banDuration << ") on element of GameRolePlayArenaPlayerBehavioursMessage.banDuration.";
  }
}

GameRolePlayArenaPlayerBehavioursMessage::GameRolePlayArenaPlayerBehavioursMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYARENAPLAYERBEHAVIOURSMESSAGE;
}

