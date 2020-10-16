#include "GameRolePlayArenaFightAnswerMessage.h"

void GameRolePlayArenaFightAnswerMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayArenaFightAnswerMessage(output);
}

void GameRolePlayArenaFightAnswerMessage::serializeAs_GameRolePlayArenaFightAnswerMessage(Writer *output)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaFightAnswerMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeVarShort((int)this->fightId);
  output->writeBool(this->accept);
}

void GameRolePlayArenaFightAnswerMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayArenaFightAnswerMessage(input);
}

void GameRolePlayArenaFightAnswerMessage::deserializeAs_GameRolePlayArenaFightAnswerMessage(Reader *input)
{
  this->_fightIdFunc(input);
  this->_acceptFunc(input);
}

void GameRolePlayArenaFightAnswerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayArenaFightAnswerMessage(tree);
}

void GameRolePlayArenaFightAnswerMessage::deserializeAsyncAs_GameRolePlayArenaFightAnswerMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameRolePlayArenaFightAnswerMessage::_fightIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayArenaFightAnswerMessage::_acceptFunc, this, std::placeholders::_1));
}

void GameRolePlayArenaFightAnswerMessage::_fightIdFunc(Reader *input)
{
  this->fightId = input->readVarUhShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaFightAnswerMessage -"<<"Forbidden value (" << this->fightId << ") on element of GameRolePlayArenaFightAnswerMessage.fightId.";
  }
}

void GameRolePlayArenaFightAnswerMessage::_acceptFunc(Reader *input)
{
  this->accept = input->readBool();
}

GameRolePlayArenaFightAnswerMessage::GameRolePlayArenaFightAnswerMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYARENAFIGHTANSWERMESSAGE;
}

