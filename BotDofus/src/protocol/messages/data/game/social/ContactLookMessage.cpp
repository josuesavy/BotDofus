#include "ContactLookMessage.h"

void ContactLookMessage::serialize(Writer *output)
{
  this->serializeAs_ContactLookMessage(output);
}

void ContactLookMessage::serializeAs_ContactLookMessage(Writer *output)
{
  if(this->requestId < 0)
  {
    qDebug()<<"ERREUR - ContactLookMessage -"<<"Forbidden value (" << this->requestId << ") on element requestId.";
  }
  output->writeVarInt((int)this->requestId);
  output->writeUTF(this->playerName);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ContactLookMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
  this->look->serializeAs_EntityLook(output);
}

void ContactLookMessage::deserialize(Reader *input)
{
  this->deserializeAs_ContactLookMessage(input);
}

void ContactLookMessage::deserializeAs_ContactLookMessage(Reader *input)
{
  this->_requestIdFunc(input);
  this->_playerNameFunc(input);
  this->_playerIdFunc(input);
  this->look = QSharedPointer<EntityLook>(new EntityLook() );
  this->look->deserialize(input);
}

void ContactLookMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ContactLookMessage(tree);
}

void ContactLookMessage::deserializeAsyncAs_ContactLookMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ContactLookMessage::_requestIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ContactLookMessage::_playerNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ContactLookMessage::_playerIdFunc, this, std::placeholders::_1));
  this->_looktree = tree.addChild(std::bind(&ContactLookMessage::_looktreeFunc, this, std::placeholders::_1));
}

void ContactLookMessage::_requestIdFunc(Reader *input)
{
  this->requestId = input->readVarUhInt();
  if(this->requestId < 0)
  {
    qDebug()<<"ERREUR - ContactLookMessage -"<<"Forbidden value (" << this->requestId << ") on element of ContactLookMessage.requestId.";
  }
}

void ContactLookMessage::_playerNameFunc(Reader *input)
{
  this->playerName = input->readUTF();
}

void ContactLookMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ContactLookMessage -"<<"Forbidden value (" << this->playerId << ") on element of ContactLookMessage.playerId.";
  }
}

void ContactLookMessage::_looktreeFunc(Reader *input)
{
  this->look = QSharedPointer<EntityLook>(new EntityLook() );
  this->look->deserializeAsync(this->_looktree);
}

ContactLookMessage::ContactLookMessage()
{
  m_type = MessageEnum::CONTACTLOOKMESSAGE;
}

