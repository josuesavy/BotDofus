#include "GameFightPauseMessage.h"

void GameFightPauseMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightPauseMessage(output);
}

void GameFightPauseMessage::serializeAs_GameFightPauseMessage(Writer *output)
{
  output->writeBool(this->isPaused);
}

void GameFightPauseMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightPauseMessage(input);
}

void GameFightPauseMessage::deserializeAs_GameFightPauseMessage(Reader *input)
{
  this->_isPausedFunc(input);
}

void GameFightPauseMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightPauseMessage(tree);
}

void GameFightPauseMessage::deserializeAsyncAs_GameFightPauseMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightPauseMessage::_isPausedFunc, this, std::placeholders::_1));
}

void GameFightPauseMessage::_isPausedFunc(Reader *input)
{
  this->isPaused = input->readBool();
}

GameFightPauseMessage::GameFightPauseMessage()
{
  m_type = MessageEnum::GAMEFIGHTPAUSEMESSAGE;
}

