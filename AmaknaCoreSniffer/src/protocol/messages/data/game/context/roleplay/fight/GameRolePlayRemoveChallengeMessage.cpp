#include "GameRolePlayRemoveChallengeMessage.h"

void GameRolePlayRemoveChallengeMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayRemoveChallengeMessage(output);
}

void GameRolePlayRemoveChallengeMessage::serializeAs_GameRolePlayRemoveChallengeMessage(Writer *output)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayRemoveChallengeMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeVarShort((int)this->fightId);
}

void GameRolePlayRemoveChallengeMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayRemoveChallengeMessage(input);
}

void GameRolePlayRemoveChallengeMessage::deserializeAs_GameRolePlayRemoveChallengeMessage(Reader *input)
{
  this->_fightIdFunc(input);
}

void GameRolePlayRemoveChallengeMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayRemoveChallengeMessage(tree);
}

void GameRolePlayRemoveChallengeMessage::deserializeAsyncAs_GameRolePlayRemoveChallengeMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameRolePlayRemoveChallengeMessage::_fightIdFunc, this, std::placeholders::_1));
}

void GameRolePlayRemoveChallengeMessage::_fightIdFunc(Reader *input)
{
  this->fightId = input->readVarUhShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayRemoveChallengeMessage -"<<"Forbidden value (" << this->fightId << ") on element of GameRolePlayRemoveChallengeMessage.fightId.";
  }
}

GameRolePlayRemoveChallengeMessage::GameRolePlayRemoveChallengeMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYREMOVECHALLENGEMESSAGE;
}

