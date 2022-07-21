#include "GameRolePlayDelayedObjectUseMessage.h"

void GameRolePlayDelayedObjectUseMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayDelayedObjectUseMessage(output);
}

void GameRolePlayDelayedObjectUseMessage::serializeAs_GameRolePlayDelayedObjectUseMessage(Writer *output)
{
  GameRolePlayDelayedActionMessage::serializeAs_GameRolePlayDelayedActionMessage(output);
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayDelayedObjectUseMessage -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
  }
  output->writeVarInt((int)this->objectGID);
}

void GameRolePlayDelayedObjectUseMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayDelayedObjectUseMessage(input);
}

void GameRolePlayDelayedObjectUseMessage::deserializeAs_GameRolePlayDelayedObjectUseMessage(Reader *input)
{
  GameRolePlayDelayedActionMessage::deserialize(input);
  this->_objectGIDFunc(input);
}

void GameRolePlayDelayedObjectUseMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayDelayedObjectUseMessage(tree);
}

void GameRolePlayDelayedObjectUseMessage::deserializeAsyncAs_GameRolePlayDelayedObjectUseMessage(FuncTree tree)
{
  GameRolePlayDelayedActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameRolePlayDelayedObjectUseMessage::_objectGIDFunc, this, std::placeholders::_1));
}

void GameRolePlayDelayedObjectUseMessage::_objectGIDFunc(Reader *input)
{
  this->objectGID = input->readVarUhInt();
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayDelayedObjectUseMessage -"<<"Forbidden value (" << this->objectGID << ") on element of GameRolePlayDelayedObjectUseMessage.objectGID.";
  }
}

GameRolePlayDelayedObjectUseMessage::GameRolePlayDelayedObjectUseMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYDELAYEDOBJECTUSEMESSAGE;
}

