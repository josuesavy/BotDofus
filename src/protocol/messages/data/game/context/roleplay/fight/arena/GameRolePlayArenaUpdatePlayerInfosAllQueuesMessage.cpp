#include "GameRolePlayArenaUpdatePlayerInfosAllQueuesMessage.h"

void GameRolePlayArenaUpdatePlayerInfosAllQueuesMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayArenaUpdatePlayerInfosAllQueuesMessage(output);
}

void GameRolePlayArenaUpdatePlayerInfosAllQueuesMessage::serializeAs_GameRolePlayArenaUpdatePlayerInfosAllQueuesMessage(Writer *output)
{
  GameRolePlayArenaUpdatePlayerInfosMessage::serializeAs_GameRolePlayArenaUpdatePlayerInfosMessage(output);
  this->team.serializeAs_ArenaRankInfos(output);
  this->duel.serializeAs_ArenaRankInfos(output);
}

void GameRolePlayArenaUpdatePlayerInfosAllQueuesMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayArenaUpdatePlayerInfosAllQueuesMessage(input);
}

void GameRolePlayArenaUpdatePlayerInfosAllQueuesMessage::deserializeAs_GameRolePlayArenaUpdatePlayerInfosAllQueuesMessage(Reader *input)
{
  GameRolePlayArenaUpdatePlayerInfosMessage::deserialize(input);
  this->team = ArenaRankInfos();
  this->team.deserialize(input);
  this->duel = ArenaRankInfos();
  this->duel.deserialize(input);
}

void GameRolePlayArenaUpdatePlayerInfosAllQueuesMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayArenaUpdatePlayerInfosAllQueuesMessage(tree);
}

void GameRolePlayArenaUpdatePlayerInfosAllQueuesMessage::deserializeAsyncAs_GameRolePlayArenaUpdatePlayerInfosAllQueuesMessage(FuncTree tree)
{
  GameRolePlayArenaUpdatePlayerInfosMessage::deserializeAsync(tree);
  this->_teamtree = tree.addChild(std::bind(&GameRolePlayArenaUpdatePlayerInfosAllQueuesMessage::_teamtreeFunc, this, std::placeholders::_1));
  this->_dueltree = tree.addChild(std::bind(&GameRolePlayArenaUpdatePlayerInfosAllQueuesMessage::_dueltreeFunc, this, std::placeholders::_1));
}

void GameRolePlayArenaUpdatePlayerInfosAllQueuesMessage::_teamtreeFunc(Reader *input)
{
  this->team = ArenaRankInfos();
  this->team.deserializeAsync(this->_teamtree);
}

void GameRolePlayArenaUpdatePlayerInfosAllQueuesMessage::_dueltreeFunc(Reader *input)
{
  this->duel = ArenaRankInfos();
  this->duel.deserializeAsync(this->_dueltree);
}

GameRolePlayArenaUpdatePlayerInfosAllQueuesMessage::GameRolePlayArenaUpdatePlayerInfosAllQueuesMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYARENAUPDATEPLAYERINFOSALLQUEUESMESSAGE;
}

