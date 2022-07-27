#include "GroupTeleportPlayerOfferMessage.h"

void GroupTeleportPlayerOfferMessage::serialize(Writer *output)
{
  this->serializeAs_GroupTeleportPlayerOfferMessage(output);
}

void GroupTeleportPlayerOfferMessage::serializeAs_GroupTeleportPlayerOfferMessage(Writer *output)
{
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GroupTeleportPlayerOfferMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  output->writeShort((short)this->worldX);
  output->writeShort((short)this->worldY);
  if(this->timeLeft < 0)
  {
    qDebug()<<"ERREUR - GroupTeleportPlayerOfferMessage -"<<"Forbidden value (" << this->timeLeft << ") on element timeLeft.";
  }
  output->writeVarInt((int)this->timeLeft);
  if(this->requesterId < 0 || this->requesterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GroupTeleportPlayerOfferMessage -"<<"Forbidden value (" << this->requesterId << ") on element requesterId.";
  }
  output->writeVarLong((double)this->requesterId);
  output->writeUTF(this->requesterName);
}

void GroupTeleportPlayerOfferMessage::deserialize(Reader *input)
{
  this->deserializeAs_GroupTeleportPlayerOfferMessage(input);
}

void GroupTeleportPlayerOfferMessage::deserializeAs_GroupTeleportPlayerOfferMessage(Reader *input)
{
  this->_mapIdFunc(input);
  this->_worldXFunc(input);
  this->_worldYFunc(input);
  this->_timeLeftFunc(input);
  this->_requesterIdFunc(input);
  this->_requesterNameFunc(input);
}

void GroupTeleportPlayerOfferMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GroupTeleportPlayerOfferMessage(tree);
}

void GroupTeleportPlayerOfferMessage::deserializeAsyncAs_GroupTeleportPlayerOfferMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GroupTeleportPlayerOfferMessage::_mapIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GroupTeleportPlayerOfferMessage::_worldXFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GroupTeleportPlayerOfferMessage::_worldYFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GroupTeleportPlayerOfferMessage::_timeLeftFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GroupTeleportPlayerOfferMessage::_requesterIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GroupTeleportPlayerOfferMessage::_requesterNameFunc, this, std::placeholders::_1));
}

void GroupTeleportPlayerOfferMessage::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GroupTeleportPlayerOfferMessage -"<<"Forbidden value (" << this->mapId << ") on element of GroupTeleportPlayerOfferMessage.mapId.";
  }
}

void GroupTeleportPlayerOfferMessage::_worldXFunc(Reader *input)
{
  this->worldX = input->readShort();
}

void GroupTeleportPlayerOfferMessage::_worldYFunc(Reader *input)
{
  this->worldY = input->readShort();
}

void GroupTeleportPlayerOfferMessage::_timeLeftFunc(Reader *input)
{
  this->timeLeft = input->readVarUhInt();
  if(this->timeLeft < 0)
  {
    qDebug()<<"ERREUR - GroupTeleportPlayerOfferMessage -"<<"Forbidden value (" << this->timeLeft << ") on element of GroupTeleportPlayerOfferMessage.timeLeft.";
  }
}

void GroupTeleportPlayerOfferMessage::_requesterIdFunc(Reader *input)
{
  this->requesterId = input->readVarUhLong();
  if(this->requesterId < 0 || this->requesterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GroupTeleportPlayerOfferMessage -"<<"Forbidden value (" << this->requesterId << ") on element of GroupTeleportPlayerOfferMessage.requesterId.";
  }
}

void GroupTeleportPlayerOfferMessage::_requesterNameFunc(Reader *input)
{
  this->requesterName = input->readUTF();
}

GroupTeleportPlayerOfferMessage::GroupTeleportPlayerOfferMessage()
{
  m_type = MessageEnum::GROUPTELEPORTPLAYEROFFERMESSAGE;
}

