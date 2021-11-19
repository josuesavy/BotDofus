#include "GameActionNoopMessage.h"

void GameActionNoopMessage::serialize(Writer *output)
{
}

void GameActionNoopMessage::serializeAs_GameActionNoopMessage(Writer *output)
{
}

void GameActionNoopMessage::deserialize(Reader *input)
{
}

void GameActionNoopMessage::deserializeAs_GameActionNoopMessage(Reader *input)
{
}

void GameActionNoopMessage::deserializeAsync(FuncTree tree)
{
}

void GameActionNoopMessage::deserializeAsyncAs_GameActionNoopMessage(FuncTree tree)
{
}

GameActionNoopMessage::GameActionNoopMessage()
{
  m_type = MessageEnum::GAMEACTIONNOOPMESSAGE;
}

