#include "GameContextQuitMessage.h"

void GameContextQuitMessage::serialize(Writer *output)
{
}

void GameContextQuitMessage::serializeAs_GameContextQuitMessage(Writer *output)
{
}

void GameContextQuitMessage::deserialize(Reader *input)
{
}

void GameContextQuitMessage::deserializeAs_GameContextQuitMessage(Reader *input)
{
}

void GameContextQuitMessage::deserializeAsync(FuncTree tree)
{
}

void GameContextQuitMessage::deserializeAsyncAs_GameContextQuitMessage(FuncTree tree)
{
}

GameContextQuitMessage::GameContextQuitMessage()
{
  m_type = MessageEnum::GAMECONTEXTQUITMESSAGE;
}

