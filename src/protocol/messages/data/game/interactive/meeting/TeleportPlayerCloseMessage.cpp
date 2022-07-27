#include "TeleportPlayerCloseMessage.h"

void TeleportPlayerCloseMessage::serialize(Writer *output)
{
  this->serializeAs_TeleportPlayerCloseMessage(output);
}

void TeleportPlayerCloseMessage::serializeAs_TeleportPlayerCloseMessage(Writer *output)
{
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TeleportPlayerCloseMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  if(this->requesterId < 0 || this->requesterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TeleportPlayerCloseMessage -"<<"Forbidden value (" << this->requesterId << ") on element requesterId.";
  }
  output->writeVarLong((double)this->requesterId);
}

void TeleportPlayerCloseMessage::deserialize(Reader *input)
{
  this->deserializeAs_TeleportPlayerCloseMessage(input);
}

void TeleportPlayerCloseMessage::deserializeAs_TeleportPlayerCloseMessage(Reader *input)
{
  this->_mapIdFunc(input);
  this->_requesterIdFunc(input);
}

void TeleportPlayerCloseMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TeleportPlayerCloseMessage(tree);
}

void TeleportPlayerCloseMessage::deserializeAsyncAs_TeleportPlayerCloseMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TeleportPlayerCloseMessage::_mapIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TeleportPlayerCloseMessage::_requesterIdFunc, this, std::placeholders::_1));
}

void TeleportPlayerCloseMessage::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TeleportPlayerCloseMessage -"<<"Forbidden value (" << this->mapId << ") on element of TeleportPlayerCloseMessage.mapId.";
  }
}

void TeleportPlayerCloseMessage::_requesterIdFunc(Reader *input)
{
  this->requesterId = input->readVarUhLong();
  if(this->requesterId < 0 || this->requesterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TeleportPlayerCloseMessage -"<<"Forbidden value (" << this->requesterId << ") on element of TeleportPlayerCloseMessage.requesterId.";
  }
}

TeleportPlayerCloseMessage::TeleportPlayerCloseMessage()
{
  m_type = MessageEnum::TELEPORTPLAYERCLOSEMESSAGE;
}

