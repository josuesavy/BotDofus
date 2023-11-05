#include "GameRolePlayDelayedActionFinishedMessage.h"

void GameRolePlayDelayedActionFinishedMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayDelayedActionFinishedMessage(output);
}

void GameRolePlayDelayedActionFinishedMessage::serializeAs_GameRolePlayDelayedActionFinishedMessage(Writer *output)
{
  if(this->delayedCharacterId < -9007199254740992 || this->delayedCharacterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayDelayedActionFinishedMessage -"<<"Forbidden value (" << this->delayedCharacterId << ") on element delayedCharacterId.";
  }
  output->writeDouble(this->delayedCharacterId);
  output->writeByte(this->delayTypeId);
}

void GameRolePlayDelayedActionFinishedMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayDelayedActionFinishedMessage(input);
}

void GameRolePlayDelayedActionFinishedMessage::deserializeAs_GameRolePlayDelayedActionFinishedMessage(Reader *input)
{
  this->_delayedCharacterIdFunc(input);
  this->_delayTypeIdFunc(input);
}

void GameRolePlayDelayedActionFinishedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayDelayedActionFinishedMessage(tree);
}

void GameRolePlayDelayedActionFinishedMessage::deserializeAsyncAs_GameRolePlayDelayedActionFinishedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameRolePlayDelayedActionFinishedMessage::_delayedCharacterIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayDelayedActionFinishedMessage::_delayTypeIdFunc, this, std::placeholders::_1));
}

void GameRolePlayDelayedActionFinishedMessage::_delayedCharacterIdFunc(Reader *input)
{
  this->delayedCharacterId = input->readDouble();
  if(this->delayedCharacterId < -9007199254740992 || this->delayedCharacterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayDelayedActionFinishedMessage -"<<"Forbidden value (" << this->delayedCharacterId << ") on element of GameRolePlayDelayedActionFinishedMessage.delayedCharacterId.";
  }
}

void GameRolePlayDelayedActionFinishedMessage::_delayTypeIdFunc(Reader *input)
{
  this->delayTypeId = input->readByte();
  if(this->delayTypeId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayDelayedActionFinishedMessage -"<<"Forbidden value (" << this->delayTypeId << ") on element of GameRolePlayDelayedActionFinishedMessage.delayTypeId.";
  }
}

GameRolePlayDelayedActionFinishedMessage::GameRolePlayDelayedActionFinishedMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYDELAYEDACTIONFINISHEDMESSAGE;
}

