#include "GameActionAcknowledgementMessage.h"

void GameActionAcknowledgementMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionAcknowledgementMessage(output);
}

void GameActionAcknowledgementMessage::serializeAs_GameActionAcknowledgementMessage(Writer *output)
{
  output->writeBool(this->valid);
  output->writeByte(this->actionId);
}

void GameActionAcknowledgementMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionAcknowledgementMessage(input);
}

void GameActionAcknowledgementMessage::deserializeAs_GameActionAcknowledgementMessage(Reader *input)
{
  this->_validFunc(input);
  this->_actionIdFunc(input);
}

void GameActionAcknowledgementMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionAcknowledgementMessage(tree);
}

void GameActionAcknowledgementMessage::deserializeAsyncAs_GameActionAcknowledgementMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameActionAcknowledgementMessage::_validFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionAcknowledgementMessage::_actionIdFunc, this, std::placeholders::_1));
}

void GameActionAcknowledgementMessage::_validFunc(Reader *input)
{
  this->valid = input->readBool();
}

void GameActionAcknowledgementMessage::_actionIdFunc(Reader *input)
{
  this->actionId = input->readByte();
}

GameActionAcknowledgementMessage::GameActionAcknowledgementMessage()
{
  m_type = MessageEnum::GAMEACTIONACKNOWLEDGEMENTMESSAGE;
}

