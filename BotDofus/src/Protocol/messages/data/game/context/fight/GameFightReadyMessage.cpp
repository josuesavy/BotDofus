#include "GameFightReadyMessage.h"

void GameFightReadyMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightReadyMessage(output);
}

void GameFightReadyMessage::serializeAs_GameFightReadyMessage(Writer *output)
{
  output->writeBool(this->isReady);
}

void GameFightReadyMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightReadyMessage(input);
}

void GameFightReadyMessage::deserializeAs_GameFightReadyMessage(Reader *input)
{
  this->_isReadyFunc(input);
}

void GameFightReadyMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightReadyMessage(tree);
}

void GameFightReadyMessage::deserializeAsyncAs_GameFightReadyMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightReadyMessage::_isReadyFunc, this, std::placeholders::_1));
}

void GameFightReadyMessage::_isReadyFunc(Reader *input)
{
  this->isReady = input->readBool();
}

GameFightReadyMessage::GameFightReadyMessage()
{
  m_type = MessageEnum::GAMEFIGHTREADYMESSAGE;
}

