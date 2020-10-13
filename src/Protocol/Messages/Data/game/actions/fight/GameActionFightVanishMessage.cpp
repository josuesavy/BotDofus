#include "GameActionFightVanishMessage.h"

void GameActionFightVanishMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightVanishMessage(output);
}

void GameActionFightVanishMessage::serializeAs_GameActionFightVanishMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightVanishMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
}

void GameActionFightVanishMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightVanishMessage(input);
}

void GameActionFightVanishMessage::deserializeAs_GameActionFightVanishMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_targetIdFunc(input);
}

void GameActionFightVanishMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightVanishMessage(tree);
}

void GameActionFightVanishMessage::deserializeAsyncAs_GameActionFightVanishMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightVanishMessage::_targetIdFunc, this, std::placeholders::_1));
}

void GameActionFightVanishMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightVanishMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightVanishMessage.targetId.";
  }
}

GameActionFightVanishMessage::GameActionFightVanishMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTVANISHMESSAGE;
}

