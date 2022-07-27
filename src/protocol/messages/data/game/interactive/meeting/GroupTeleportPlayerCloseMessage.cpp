#include "GroupTeleportPlayerCloseMessage.h"

void GroupTeleportPlayerCloseMessage::serialize(Writer *output)
{
  this->serializeAs_GroupTeleportPlayerCloseMessage(output);
}

void GroupTeleportPlayerCloseMessage::serializeAs_GroupTeleportPlayerCloseMessage(Writer *output)
{
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GroupTeleportPlayerCloseMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  if(this->requesterId < 0 || this->requesterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GroupTeleportPlayerCloseMessage -"<<"Forbidden value (" << this->requesterId << ") on element requesterId.";
  }
  output->writeVarLong((double)this->requesterId);
}

void GroupTeleportPlayerCloseMessage::deserialize(Reader *input)
{
  this->deserializeAs_GroupTeleportPlayerCloseMessage(input);
}

void GroupTeleportPlayerCloseMessage::deserializeAs_GroupTeleportPlayerCloseMessage(Reader *input)
{
  this->_mapIdFunc(input);
  this->_requesterIdFunc(input);
}

void GroupTeleportPlayerCloseMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GroupTeleportPlayerCloseMessage(tree);
}

void GroupTeleportPlayerCloseMessage::deserializeAsyncAs_GroupTeleportPlayerCloseMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GroupTeleportPlayerCloseMessage::_mapIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GroupTeleportPlayerCloseMessage::_requesterIdFunc, this, std::placeholders::_1));
}

void GroupTeleportPlayerCloseMessage::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GroupTeleportPlayerCloseMessage -"<<"Forbidden value (" << this->mapId << ") on element of GroupTeleportPlayerCloseMessage.mapId.";
  }
}

void GroupTeleportPlayerCloseMessage::_requesterIdFunc(Reader *input)
{
  this->requesterId = input->readVarUhLong();
  if(this->requesterId < 0 || this->requesterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GroupTeleportPlayerCloseMessage -"<<"Forbidden value (" << this->requesterId << ") on element of GroupTeleportPlayerCloseMessage.requesterId.";
  }
}

GroupTeleportPlayerCloseMessage::GroupTeleportPlayerCloseMessage()
{
  m_type = MessageEnum::GROUPTELEPORTPLAYERCLOSEMESSAGE;
}

