#include "GameContextRefreshEntityLookMessage.h"

void GameContextRefreshEntityLookMessage::serialize(Writer *output)
{
  this->serializeAs_GameContextRefreshEntityLookMessage(output);
}

void GameContextRefreshEntityLookMessage::serializeAs_GameContextRefreshEntityLookMessage(Writer *output)
{
  if(this->id < -9007199254740992 || this->id > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameContextRefreshEntityLookMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeDouble(this->id);
  this->look.serializeAs_EntityLook(output);
}

void GameContextRefreshEntityLookMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameContextRefreshEntityLookMessage(input);
}

void GameContextRefreshEntityLookMessage::deserializeAs_GameContextRefreshEntityLookMessage(Reader *input)
{
  this->_idFunc(input);
  this->look = EntityLook();
  this->look.deserialize(input);
}

void GameContextRefreshEntityLookMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameContextRefreshEntityLookMessage(tree);
}

void GameContextRefreshEntityLookMessage::deserializeAsyncAs_GameContextRefreshEntityLookMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameContextRefreshEntityLookMessage::_idFunc, this, std::placeholders::_1));
  this->_looktree = tree.addChild(std::bind(&GameContextRefreshEntityLookMessage::_looktreeFunc, this, std::placeholders::_1));
}

void GameContextRefreshEntityLookMessage::_idFunc(Reader *input)
{
  this->id = input->readDouble();
  if(this->id < -9007199254740992 || this->id > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameContextRefreshEntityLookMessage -"<<"Forbidden value (" << this->id << ") on element of GameContextRefreshEntityLookMessage.id.";
  }
}

void GameContextRefreshEntityLookMessage::_looktreeFunc(Reader *input)
{
  this->look = EntityLook();
  this->look.deserializeAsync(this->_looktree);
}

GameContextRefreshEntityLookMessage::GameContextRefreshEntityLookMessage()
{
  m_type = MessageEnum::GAMECONTEXTREFRESHENTITYLOOKMESSAGE;
}

