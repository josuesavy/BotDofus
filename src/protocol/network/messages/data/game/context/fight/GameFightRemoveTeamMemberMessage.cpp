#include "GameFightRemoveTeamMemberMessage.h"

void GameFightRemoveTeamMemberMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightRemoveTeamMemberMessage(output);
}

void GameFightRemoveTeamMemberMessage::serializeAs_GameFightRemoveTeamMemberMessage(Writer *output)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameFightRemoveTeamMemberMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeVarShort((int)this->fightId);
  output->writeByte(this->teamId);
  if(this->charId < -9007199254740992 || this->charId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameFightRemoveTeamMemberMessage -"<<"Forbidden value (" << this->charId << ") on element charId.";
  }
  output->writeDouble(this->charId);
}

void GameFightRemoveTeamMemberMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightRemoveTeamMemberMessage(input);
}

void GameFightRemoveTeamMemberMessage::deserializeAs_GameFightRemoveTeamMemberMessage(Reader *input)
{
  this->_fightIdFunc(input);
  this->_teamIdFunc(input);
  this->_charIdFunc(input);
}

void GameFightRemoveTeamMemberMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightRemoveTeamMemberMessage(tree);
}

void GameFightRemoveTeamMemberMessage::deserializeAsyncAs_GameFightRemoveTeamMemberMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightRemoveTeamMemberMessage::_fightIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightRemoveTeamMemberMessage::_teamIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightRemoveTeamMemberMessage::_charIdFunc, this, std::placeholders::_1));
}

void GameFightRemoveTeamMemberMessage::_fightIdFunc(Reader *input)
{
  this->fightId = input->readVarUhShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameFightRemoveTeamMemberMessage -"<<"Forbidden value (" << this->fightId << ") on element of GameFightRemoveTeamMemberMessage.fightId.";
  }
}

void GameFightRemoveTeamMemberMessage::_teamIdFunc(Reader *input)
{
  this->teamId = input->readByte();
  if(this->teamId < 0)
  {
    qDebug()<<"ERREUR - GameFightRemoveTeamMemberMessage -"<<"Forbidden value (" << this->teamId << ") on element of GameFightRemoveTeamMemberMessage.teamId.";
  }
}

void GameFightRemoveTeamMemberMessage::_charIdFunc(Reader *input)
{
  this->charId = input->readDouble();
  if(this->charId < -9007199254740992 || this->charId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameFightRemoveTeamMemberMessage -"<<"Forbidden value (" << this->charId << ") on element of GameFightRemoveTeamMemberMessage.charId.";
  }
}

GameFightRemoveTeamMemberMessage::GameFightRemoveTeamMemberMessage()
{
  m_type = MessageEnum::GAMEFIGHTREMOVETEAMMEMBERMESSAGE;
}

