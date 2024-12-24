#include "TeleportPlayerOfferMessage.h"

void TeleportPlayerOfferMessage::serialize(Writer *output)
{
  this->serializeAs_TeleportPlayerOfferMessage(output);
}

void TeleportPlayerOfferMessage::serializeAs_TeleportPlayerOfferMessage(Writer *output)
{
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TeleportPlayerOfferMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  output->writeUTF(this->message);
  if(this->timeLeft < 0)
  {
    qDebug()<<"ERREUR - TeleportPlayerOfferMessage -"<<"Forbidden value (" << this->timeLeft << ") on element timeLeft.";
  }
  output->writeVarInt((int)this->timeLeft);
  if(this->requesterId < 0 || this->requesterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TeleportPlayerOfferMessage -"<<"Forbidden value (" << this->requesterId << ") on element requesterId.";
  }
  output->writeVarLong((double)this->requesterId);
}

void TeleportPlayerOfferMessage::deserialize(Reader *input)
{
  this->deserializeAs_TeleportPlayerOfferMessage(input);
}

void TeleportPlayerOfferMessage::deserializeAs_TeleportPlayerOfferMessage(Reader *input)
{
  this->_mapIdFunc(input);
  this->_messageFunc(input);
  this->_timeLeftFunc(input);
  this->_requesterIdFunc(input);
}

void TeleportPlayerOfferMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TeleportPlayerOfferMessage(tree);
}

void TeleportPlayerOfferMessage::deserializeAsyncAs_TeleportPlayerOfferMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TeleportPlayerOfferMessage::_mapIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TeleportPlayerOfferMessage::_messageFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TeleportPlayerOfferMessage::_timeLeftFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TeleportPlayerOfferMessage::_requesterIdFunc, this, std::placeholders::_1));
}

void TeleportPlayerOfferMessage::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TeleportPlayerOfferMessage -"<<"Forbidden value (" << this->mapId << ") on element of TeleportPlayerOfferMessage.mapId.";
  }
}

void TeleportPlayerOfferMessage::_messageFunc(Reader *input)
{
  this->message = input->readUTF();
}

void TeleportPlayerOfferMessage::_timeLeftFunc(Reader *input)
{
  this->timeLeft = input->readVarUhInt();
  if(this->timeLeft < 0)
  {
    qDebug()<<"ERREUR - TeleportPlayerOfferMessage -"<<"Forbidden value (" << this->timeLeft << ") on element of TeleportPlayerOfferMessage.timeLeft.";
  }
}

void TeleportPlayerOfferMessage::_requesterIdFunc(Reader *input)
{
  this->requesterId = input->readVarUhLong();
  if(this->requesterId < 0 || this->requesterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TeleportPlayerOfferMessage -"<<"Forbidden value (" << this->requesterId << ") on element of TeleportPlayerOfferMessage.requesterId.";
  }
}

TeleportPlayerOfferMessage::TeleportPlayerOfferMessage()
{
  m_type = MessageEnum::TELEPORTPLAYEROFFERMESSAGE;
}

