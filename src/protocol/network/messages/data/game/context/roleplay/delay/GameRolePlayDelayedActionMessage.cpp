#include "GameRolePlayDelayedActionMessage.h"

void GameRolePlayDelayedActionMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayDelayedActionMessage(output);
}

void GameRolePlayDelayedActionMessage::serializeAs_GameRolePlayDelayedActionMessage(Writer *output)
{
  if(this->delayedCharacterId < -9007199254740992 || this->delayedCharacterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayDelayedActionMessage -"<<"Forbidden value (" << this->delayedCharacterId << ") on element delayedCharacterId.";
  }
  output->writeDouble(this->delayedCharacterId);
  output->writeByte(this->delayTypeId);
  if(this->delayEndTime < 0 || this->delayEndTime > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayDelayedActionMessage -"<<"Forbidden value (" << this->delayEndTime << ") on element delayEndTime.";
  }
  output->writeDouble(this->delayEndTime);
}

void GameRolePlayDelayedActionMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayDelayedActionMessage(input);
}

void GameRolePlayDelayedActionMessage::deserializeAs_GameRolePlayDelayedActionMessage(Reader *input)
{
  this->_delayedCharacterIdFunc(input);
  this->_delayTypeIdFunc(input);
  this->_delayEndTimeFunc(input);
}

void GameRolePlayDelayedActionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayDelayedActionMessage(tree);
}

void GameRolePlayDelayedActionMessage::deserializeAsyncAs_GameRolePlayDelayedActionMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameRolePlayDelayedActionMessage::_delayedCharacterIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayDelayedActionMessage::_delayTypeIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayDelayedActionMessage::_delayEndTimeFunc, this, std::placeholders::_1));
}

void GameRolePlayDelayedActionMessage::_delayedCharacterIdFunc(Reader *input)
{
  this->delayedCharacterId = input->readDouble();
  if(this->delayedCharacterId < -9007199254740992 || this->delayedCharacterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayDelayedActionMessage -"<<"Forbidden value (" << this->delayedCharacterId << ") on element of GameRolePlayDelayedActionMessage.delayedCharacterId.";
  }
}

void GameRolePlayDelayedActionMessage::_delayTypeIdFunc(Reader *input)
{
  this->delayTypeId = input->readByte();
  if(this->delayTypeId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayDelayedActionMessage -"<<"Forbidden value (" << this->delayTypeId << ") on element of GameRolePlayDelayedActionMessage.delayTypeId.";
  }
}

void GameRolePlayDelayedActionMessage::_delayEndTimeFunc(Reader *input)
{
  this->delayEndTime = input->readDouble();
  if(this->delayEndTime < 0 || this->delayEndTime > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameRolePlayDelayedActionMessage -"<<"Forbidden value (" << this->delayEndTime << ") on element of GameRolePlayDelayedActionMessage.delayEndTime.";
  }
}

GameRolePlayDelayedActionMessage::GameRolePlayDelayedActionMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYDELAYEDACTIONMESSAGE;
}

