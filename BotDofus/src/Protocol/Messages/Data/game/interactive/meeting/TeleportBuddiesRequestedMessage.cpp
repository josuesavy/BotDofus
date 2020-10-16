#include "TeleportBuddiesRequestedMessage.h"

void TeleportBuddiesRequestedMessage::serialize(Writer *output)
{
  this->serializeAs_TeleportBuddiesRequestedMessage(output);
}

void TeleportBuddiesRequestedMessage::serializeAs_TeleportBuddiesRequestedMessage(Writer *output)
{
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - TeleportBuddiesRequestedMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  output->writeVarShort((int)this->dungeonId);
  if(this->inviterId < 0 || this->inviterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TeleportBuddiesRequestedMessage -"<<"Forbidden value (" << this->inviterId << ") on element inviterId.";
  }
  output->writeVarLong((double)this->inviterId);
  output->writeShort((short)this->invalidBuddiesIds.size());
  for(uint _i3 = 0; _i3 < this->invalidBuddiesIds.size(); _i3++)
  {
    if(this->invalidBuddiesIds[_i3] < 0 || this->invalidBuddiesIds[_i3] > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - TeleportBuddiesRequestedMessage -"<<"Forbidden value (" << this->invalidBuddiesIds[_i3] << ") on element 3 (starting at 1) of invalidBuddiesIds.";
    }
    output->writeVarLong((double)this->invalidBuddiesIds[_i3]);
  }
}

void TeleportBuddiesRequestedMessage::deserialize(Reader *input)
{
  this->deserializeAs_TeleportBuddiesRequestedMessage(input);
}

void TeleportBuddiesRequestedMessage::deserializeAs_TeleportBuddiesRequestedMessage(Reader *input)
{
  auto _val3 = NULL;
  this->_dungeonIdFunc(input);
  this->_inviterIdFunc(input);
  uint _invalidBuddiesIdsLen = input->readUShort();
  for(uint _i3 = 0; _i3 < _invalidBuddiesIdsLen; _i3++)
  {
    _val3 = input->readVarUhLong();
    if(_val3 < 0 || _val3 > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - TeleportBuddiesRequestedMessage -"<<"Forbidden value (" << _val3 << ") on elements of invalidBuddiesIds.";
    }
    this->invalidBuddiesIds.append(_val3);
  }
}

void TeleportBuddiesRequestedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TeleportBuddiesRequestedMessage(tree);
}

void TeleportBuddiesRequestedMessage::deserializeAsyncAs_TeleportBuddiesRequestedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TeleportBuddiesRequestedMessage::_dungeonIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TeleportBuddiesRequestedMessage::_inviterIdFunc, this, std::placeholders::_1));
  this->_invalidBuddiesIdstree = tree.addChild(std::bind(&TeleportBuddiesRequestedMessage::_invalidBuddiesIdstreeFunc, this, std::placeholders::_1));
}

void TeleportBuddiesRequestedMessage::_dungeonIdFunc(Reader *input)
{
  this->dungeonId = input->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - TeleportBuddiesRequestedMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of TeleportBuddiesRequestedMessage.dungeonId.";
  }
}

void TeleportBuddiesRequestedMessage::_inviterIdFunc(Reader *input)
{
  this->inviterId = input->readVarUhLong();
  if(this->inviterId < 0 || this->inviterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TeleportBuddiesRequestedMessage -"<<"Forbidden value (" << this->inviterId << ") on element of TeleportBuddiesRequestedMessage.inviterId.";
  }
}

void TeleportBuddiesRequestedMessage::_invalidBuddiesIdstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_invalidBuddiesIdstree.addChild(std::bind(&TeleportBuddiesRequestedMessage::_invalidBuddiesIdsFunc, this, std::placeholders::_1));
  }
}

void TeleportBuddiesRequestedMessage::_invalidBuddiesIdsFunc(Reader *input)
{
  double _val = input->readVarUhLong();
  if(_val < 0 || _val > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TeleportBuddiesRequestedMessage -"<<"Forbidden value (" << _val << ") on elements of invalidBuddiesIds.";
  }
  this->invalidBuddiesIds.append(_val);
}

TeleportBuddiesRequestedMessage::TeleportBuddiesRequestedMessage()
{
  m_type = MessageEnum::TELEPORTBUDDIESREQUESTEDMESSAGE;
}

