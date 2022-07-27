#include "GameFightUpdateTeamMessage.h"

void GameFightUpdateTeamMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightUpdateTeamMessage(output);
}

void GameFightUpdateTeamMessage::serializeAs_GameFightUpdateTeamMessage(Writer *output)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameFightUpdateTeamMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeVarShort((int)this->fightId);
  this->team->serializeAs_FightTeamInformations(output);
}

void GameFightUpdateTeamMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightUpdateTeamMessage(input);
}

void GameFightUpdateTeamMessage::deserializeAs_GameFightUpdateTeamMessage(Reader *input)
{
  this->_fightIdFunc(input);
  this->team = QSharedPointer<FightTeamInformations>(new FightTeamInformations() );
  this->team->deserialize(input);
}

void GameFightUpdateTeamMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightUpdateTeamMessage(tree);
}

void GameFightUpdateTeamMessage::deserializeAsyncAs_GameFightUpdateTeamMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightUpdateTeamMessage::_fightIdFunc, this, std::placeholders::_1));
  this->_teamtree = tree.addChild(std::bind(&GameFightUpdateTeamMessage::_teamtreeFunc, this, std::placeholders::_1));
}

void GameFightUpdateTeamMessage::_fightIdFunc(Reader *input)
{
  this->fightId = input->readVarUhShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameFightUpdateTeamMessage -"<<"Forbidden value (" << this->fightId << ") on element of GameFightUpdateTeamMessage.fightId.";
  }
}

void GameFightUpdateTeamMessage::_teamtreeFunc(Reader *input)
{
  this->team = QSharedPointer<FightTeamInformations>(new FightTeamInformations() );
  this->team->deserializeAsync(this->_teamtree);
}

GameFightUpdateTeamMessage::GameFightUpdateTeamMessage()
{
  m_type = MessageEnum::GAMEFIGHTUPDATETEAMMESSAGE;
}

