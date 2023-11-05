#include "GameFightTurnReadyMessage.h"

void GameFightTurnReadyMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightTurnReadyMessage(output);
}

void GameFightTurnReadyMessage::serializeAs_GameFightTurnReadyMessage(Writer *output)
{
  output->writeBool(this->isReady);
}

void GameFightTurnReadyMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightTurnReadyMessage(input);
}

void GameFightTurnReadyMessage::deserializeAs_GameFightTurnReadyMessage(Reader *input)
{
  this->_isReadyFunc(input);
}

void GameFightTurnReadyMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightTurnReadyMessage(tree);
}

void GameFightTurnReadyMessage::deserializeAsyncAs_GameFightTurnReadyMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightTurnReadyMessage::_isReadyFunc, this, std::placeholders::_1));
}

void GameFightTurnReadyMessage::_isReadyFunc(Reader *input)
{
  this->isReady = input->readBool();
}

GameFightTurnReadyMessage::GameFightTurnReadyMessage()
{
  m_type = MessageEnum::GAMEFIGHTTURNREADYMESSAGE;
}

