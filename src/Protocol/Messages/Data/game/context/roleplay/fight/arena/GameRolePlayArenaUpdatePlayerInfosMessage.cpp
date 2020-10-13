#include "GameRolePlayArenaUpdatePlayerInfosMessage.h"

void GameRolePlayArenaUpdatePlayerInfosMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayArenaUpdatePlayerInfosMessage(output);
}

void GameRolePlayArenaUpdatePlayerInfosMessage::serializeAs_GameRolePlayArenaUpdatePlayerInfosMessage(Writer *output)
{
  this->solo.serializeAs_ArenaRankInfos(output);
}

void GameRolePlayArenaUpdatePlayerInfosMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayArenaUpdatePlayerInfosMessage(input);
}

void GameRolePlayArenaUpdatePlayerInfosMessage::deserializeAs_GameRolePlayArenaUpdatePlayerInfosMessage(Reader *input)
{
  this->solo = ArenaRankInfos();
  this->solo.deserialize(input);
}

void GameRolePlayArenaUpdatePlayerInfosMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayArenaUpdatePlayerInfosMessage(tree);
}

void GameRolePlayArenaUpdatePlayerInfosMessage::deserializeAsyncAs_GameRolePlayArenaUpdatePlayerInfosMessage(FuncTree tree)
{
  this->_solotree = tree.addChild(std::bind(&GameRolePlayArenaUpdatePlayerInfosMessage::_solotreeFunc, this, std::placeholders::_1));
}

void GameRolePlayArenaUpdatePlayerInfosMessage::_solotreeFunc(Reader *input)
{
  this->solo = ArenaRankInfos();
  this->solo.deserializeAsync(this->_solotree);
}

GameRolePlayArenaUpdatePlayerInfosMessage::GameRolePlayArenaUpdatePlayerInfosMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYARENAUPDATEPLAYERINFOSMESSAGE;
}

