#include "GameRolePlayPlayerFightFriendlyRequestedMessage.h"

void GameRolePlayPlayerFightFriendlyRequestedMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayPlayerFightFriendlyRequestedMessage(output);
}

void GameRolePlayPlayerFightFriendlyRequestedMessage::serializeAs_GameRolePlayPlayerFightFriendlyRequestedMessage(Writer *output)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerFightFriendlyRequestedMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeVarShort((int)this->fightId);
  if(this->sourceId < 0 || this->sourceId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerFightFriendlyRequestedMessage -"<<"Forbidden value (" << this->sourceId << ") on element sourceId.";
  }
  output->writeVarLong((double)this->sourceId);
  if(this->targetId < 0 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerFightFriendlyRequestedMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeVarLong((double)this->targetId);
}

void GameRolePlayPlayerFightFriendlyRequestedMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayPlayerFightFriendlyRequestedMessage(input);
}

void GameRolePlayPlayerFightFriendlyRequestedMessage::deserializeAs_GameRolePlayPlayerFightFriendlyRequestedMessage(Reader *input)
{
  this->_fightIdFunc(input);
  this->_sourceIdFunc(input);
  this->_targetIdFunc(input);
}

void GameRolePlayPlayerFightFriendlyRequestedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayPlayerFightFriendlyRequestedMessage(tree);
}

void GameRolePlayPlayerFightFriendlyRequestedMessage::deserializeAsyncAs_GameRolePlayPlayerFightFriendlyRequestedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameRolePlayPlayerFightFriendlyRequestedMessage::_fightIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayPlayerFightFriendlyRequestedMessage::_sourceIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayPlayerFightFriendlyRequestedMessage::_targetIdFunc, this, std::placeholders::_1));
}

void GameRolePlayPlayerFightFriendlyRequestedMessage::_fightIdFunc(Reader *input)
{
  this->fightId = input->readVarUhShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerFightFriendlyRequestedMessage -"<<"Forbidden value (" << this->fightId << ") on element of GameRolePlayPlayerFightFriendlyRequestedMessage.fightId.";
  }
}

void GameRolePlayPlayerFightFriendlyRequestedMessage::_sourceIdFunc(Reader *input)
{
  this->sourceId = input->readVarUhLong();
  if(this->sourceId < 0 || this->sourceId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerFightFriendlyRequestedMessage -"<<"Forbidden value (" << this->sourceId << ") on element of GameRolePlayPlayerFightFriendlyRequestedMessage.sourceId.";
  }
}

void GameRolePlayPlayerFightFriendlyRequestedMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readVarUhLong();
  if(this->targetId < 0 || this->targetId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerFightFriendlyRequestedMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameRolePlayPlayerFightFriendlyRequestedMessage.targetId.";
  }
}

GameRolePlayPlayerFightFriendlyRequestedMessage::GameRolePlayPlayerFightFriendlyRequestedMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYPLAYERFIGHTFRIENDLYREQUESTEDMESSAGE;
}

