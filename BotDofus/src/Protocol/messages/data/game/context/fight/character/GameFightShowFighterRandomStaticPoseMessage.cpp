#include "GameFightShowFighterRandomStaticPoseMessage.h"

void GameFightShowFighterRandomStaticPoseMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightShowFighterRandomStaticPoseMessage(output);
}

void GameFightShowFighterRandomStaticPoseMessage::serializeAs_GameFightShowFighterRandomStaticPoseMessage(Writer *output)
{
  GameFightShowFighterMessage::serializeAs_GameFightShowFighterMessage(output);
}

void GameFightShowFighterRandomStaticPoseMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightShowFighterRandomStaticPoseMessage(input);
}

void GameFightShowFighterRandomStaticPoseMessage::deserializeAs_GameFightShowFighterRandomStaticPoseMessage(Reader *input)
{
  GameFightShowFighterMessage::deserialize(input);
}

void GameFightShowFighterRandomStaticPoseMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightShowFighterRandomStaticPoseMessage(tree);
}

void GameFightShowFighterRandomStaticPoseMessage::deserializeAsyncAs_GameFightShowFighterRandomStaticPoseMessage(FuncTree tree)
{
  GameFightShowFighterMessage::deserializeAsync(tree);
}

GameFightShowFighterRandomStaticPoseMessage::GameFightShowFighterRandomStaticPoseMessage()
{
  m_type = MessageEnum::GAMEFIGHTSHOWFIGHTERRANDOMSTATICPOSEMESSAGE;
}

