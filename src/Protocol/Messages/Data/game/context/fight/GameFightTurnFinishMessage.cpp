#include "GameFightTurnFinishMessage.h"

void GameFightTurnFinishMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightTurnFinishMessage(output);
}

void GameFightTurnFinishMessage::serializeAs_GameFightTurnFinishMessage(Writer *output)
{
  output->writeBool(this->isAfk);
}

void GameFightTurnFinishMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightTurnFinishMessage(input);
}

void GameFightTurnFinishMessage::deserializeAs_GameFightTurnFinishMessage(Reader *input)
{
  this->_isAfkFunc(input);
}

void GameFightTurnFinishMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightTurnFinishMessage(tree);
}

void GameFightTurnFinishMessage::deserializeAsyncAs_GameFightTurnFinishMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightTurnFinishMessage::_isAfkFunc, this, std::placeholders::_1));
}

void GameFightTurnFinishMessage::_isAfkFunc(Reader *input)
{
  this->isAfk = input->readBool();
}

GameFightTurnFinishMessage::GameFightTurnFinishMessage()
{
  m_type = MessageEnum::GAMEFIGHTTURNFINISHMESSAGE;
}

