#include "GameRolePlayPlayerFightFriendlyAnswerMessage.h"

void GameRolePlayPlayerFightFriendlyAnswerMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayPlayerFightFriendlyAnswerMessage(output);
}

void GameRolePlayPlayerFightFriendlyAnswerMessage::serializeAs_GameRolePlayPlayerFightFriendlyAnswerMessage(Writer *output)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerFightFriendlyAnswerMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeVarShort((int)this->fightId);
  output->writeBool(this->accept);
}

void GameRolePlayPlayerFightFriendlyAnswerMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayPlayerFightFriendlyAnswerMessage(input);
}

void GameRolePlayPlayerFightFriendlyAnswerMessage::deserializeAs_GameRolePlayPlayerFightFriendlyAnswerMessage(Reader *input)
{
  this->_fightIdFunc(input);
  this->_acceptFunc(input);
}

void GameRolePlayPlayerFightFriendlyAnswerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayPlayerFightFriendlyAnswerMessage(tree);
}

void GameRolePlayPlayerFightFriendlyAnswerMessage::deserializeAsyncAs_GameRolePlayPlayerFightFriendlyAnswerMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameRolePlayPlayerFightFriendlyAnswerMessage::_fightIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayPlayerFightFriendlyAnswerMessage::_acceptFunc, this, std::placeholders::_1));
}

void GameRolePlayPlayerFightFriendlyAnswerMessage::_fightIdFunc(Reader *input)
{
  this->fightId = input->readVarUhShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerFightFriendlyAnswerMessage -"<<"Forbidden value (" << this->fightId << ") on element of GameRolePlayPlayerFightFriendlyAnswerMessage.fightId.";
  }
}

void GameRolePlayPlayerFightFriendlyAnswerMessage::_acceptFunc(Reader *input)
{
  this->accept = input->readBool();
}

GameRolePlayPlayerFightFriendlyAnswerMessage::GameRolePlayPlayerFightFriendlyAnswerMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYPLAYERFIGHTFRIENDLYANSWERMESSAGE;
}

