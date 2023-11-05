#include "PartyCancelInvitationNotificationMessage.h"

void PartyCancelInvitationNotificationMessage::serialize(Writer *output)
{
  this->serializeAs_PartyCancelInvitationNotificationMessage(output);
}

void PartyCancelInvitationNotificationMessage::serializeAs_PartyCancelInvitationNotificationMessage(Writer *output)
{
  AbstractPartyEventMessage::serializeAs_AbstractPartyEventMessage(output);
  if(this->cancelerId < 0 || this->cancelerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyCancelInvitationNotificationMessage -"<<"Forbidden value (" << this->cancelerId << ") on element cancelerId.";
  }
  output->writeVarLong((double)this->cancelerId);
  if(this->guestId < 0 || this->guestId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyCancelInvitationNotificationMessage -"<<"Forbidden value (" << this->guestId << ") on element guestId.";
  }
  output->writeVarLong((double)this->guestId);
}

void PartyCancelInvitationNotificationMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyCancelInvitationNotificationMessage(input);
}

void PartyCancelInvitationNotificationMessage::deserializeAs_PartyCancelInvitationNotificationMessage(Reader *input)
{
  AbstractPartyEventMessage::deserialize(input);
  this->_cancelerIdFunc(input);
  this->_guestIdFunc(input);
}

void PartyCancelInvitationNotificationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyCancelInvitationNotificationMessage(tree);
}

void PartyCancelInvitationNotificationMessage::deserializeAsyncAs_PartyCancelInvitationNotificationMessage(FuncTree tree)
{
  AbstractPartyEventMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyCancelInvitationNotificationMessage::_cancelerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyCancelInvitationNotificationMessage::_guestIdFunc, this, std::placeholders::_1));
}

void PartyCancelInvitationNotificationMessage::_cancelerIdFunc(Reader *input)
{
  this->cancelerId = input->readVarUhLong();
  if(this->cancelerId < 0 || this->cancelerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyCancelInvitationNotificationMessage -"<<"Forbidden value (" << this->cancelerId << ") on element of PartyCancelInvitationNotificationMessage.cancelerId.";
  }
}

void PartyCancelInvitationNotificationMessage::_guestIdFunc(Reader *input)
{
  this->guestId = input->readVarUhLong();
  if(this->guestId < 0 || this->guestId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyCancelInvitationNotificationMessage -"<<"Forbidden value (" << this->guestId << ") on element of PartyCancelInvitationNotificationMessage.guestId.";
  }
}

PartyCancelInvitationNotificationMessage::PartyCancelInvitationNotificationMessage()
{
  m_type = MessageEnum::PARTYCANCELINVITATIONNOTIFICATIONMESSAGE;
}

