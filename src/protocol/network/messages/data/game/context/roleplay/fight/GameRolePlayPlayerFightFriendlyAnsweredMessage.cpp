#include "GameRolePlayPlayerFightFriendlyAnsweredMessage.h"

void GameRolePlayPlayerFightFriendlyAnsweredMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayPlayerFightFriendlyAnsweredMessage(output);
}

void GameRolePlayPlayerFightFriendlyAnsweredMessage::serializeAs_GameRolePlayPlayerFightFriendlyAnsweredMessage(Writer *output)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerFightFriendlyAnsweredMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeVarShort((int)this->fightId);
  if(this->sourceId < 0 || this->sourceId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerFightFriendlyAnsweredMessage -"<<"Forbidden value (" << this->sourceId << ") on element sourceId.";
  }
  output->writeVarLong((double)this->sourceId);
  if(this->targetId < 0 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerFightFriendlyAnsweredMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeVarLong((double)this->targetId);
  output->writeBool(this->accept);
}

void GameRolePlayPlayerFightFriendlyAnsweredMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayPlayerFightFriendlyAnsweredMessage(input);
}

void GameRolePlayPlayerFightFriendlyAnsweredMessage::deserializeAs_GameRolePlayPlayerFightFriendlyAnsweredMessage(Reader *input)
{
  this->_fightIdFunc(input);
  this->_sourceIdFunc(input);
  this->_targetIdFunc(input);
  this->_acceptFunc(input);
}

void GameRolePlayPlayerFightFriendlyAnsweredMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayPlayerFightFriendlyAnsweredMessage(tree);
}

void GameRolePlayPlayerFightFriendlyAnsweredMessage::deserializeAsyncAs_GameRolePlayPlayerFightFriendlyAnsweredMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameRolePlayPlayerFightFriendlyAnsweredMessage::_fightIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayPlayerFightFriendlyAnsweredMessage::_sourceIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayPlayerFightFriendlyAnsweredMessage::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayPlayerFightFriendlyAnsweredMessage::_acceptFunc, this, std::placeholders::_1));
}

void GameRolePlayPlayerFightFriendlyAnsweredMessage::_fightIdFunc(Reader *input)
{
  this->fightId = input->readVarUhShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerFightFriendlyAnsweredMessage -"<<"Forbidden value (" << this->fightId << ") on element of GameRolePlayPlayerFightFriendlyAnsweredMessage.fightId.";
  }
}

void GameRolePlayPlayerFightFriendlyAnsweredMessage::_sourceIdFunc(Reader *input)
{
  this->sourceId = input->readVarUhLong();
  if(this->sourceId < 0 || this->sourceId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerFightFriendlyAnsweredMessage -"<<"Forbidden value (" << this->sourceId << ") on element of GameRolePlayPlayerFightFriendlyAnsweredMessage.sourceId.";
  }
}

void GameRolePlayPlayerFightFriendlyAnsweredMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readVarUhLong();
  if(this->targetId < 0 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerFightFriendlyAnsweredMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameRolePlayPlayerFightFriendlyAnsweredMessage.targetId.";
  }
}

void GameRolePlayPlayerFightFriendlyAnsweredMessage::_acceptFunc(Reader *input)
{
  this->accept = input->readBool();
}

GameRolePlayPlayerFightFriendlyAnsweredMessage::GameRolePlayPlayerFightFriendlyAnsweredMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYPLAYERFIGHTFRIENDLYANSWEREDMESSAGE;
}

