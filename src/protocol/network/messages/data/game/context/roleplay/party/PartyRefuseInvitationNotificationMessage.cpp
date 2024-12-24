#include "PartyRefuseInvitationNotificationMessage.h"

void PartyRefuseInvitationNotificationMessage::serialize(Writer *output)
{
  this->serializeAs_PartyRefuseInvitationNotificationMessage(output);
}

void PartyRefuseInvitationNotificationMessage::serializeAs_PartyRefuseInvitationNotificationMessage(Writer *output)
{
  AbstractPartyEventMessage::serializeAs_AbstractPartyEventMessage(output);
  if(this->guestId < 0 || this->guestId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyRefuseInvitationNotificationMessage -"<<"Forbidden value (" << this->guestId << ") on element guestId.";
  }
  output->writeVarLong((double)this->guestId);
}

void PartyRefuseInvitationNotificationMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyRefuseInvitationNotificationMessage(input);
}

void PartyRefuseInvitationNotificationMessage::deserializeAs_PartyRefuseInvitationNotificationMessage(Reader *input)
{
  AbstractPartyEventMessage::deserialize(input);
  this->_guestIdFunc(input);
}

void PartyRefuseInvitationNotificationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyRefuseInvitationNotificationMessage(tree);
}

void PartyRefuseInvitationNotificationMessage::deserializeAsyncAs_PartyRefuseInvitationNotificationMessage(FuncTree tree)
{
  AbstractPartyEventMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyRefuseInvitationNotificationMessage::_guestIdFunc, this, std::placeholders::_1));
}

void PartyRefuseInvitationNotificationMessage::_guestIdFunc(Reader *input)
{
  this->guestId = input->readVarUhLong();
  if(this->guestId < 0 || this->guestId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyRefuseInvitationNotificationMessage -"<<"Forbidden value (" << this->guestId << ") on element of PartyRefuseInvitationNotificationMessage.guestId.";
  }
}

PartyRefuseInvitationNotificationMessage::PartyRefuseInvitationNotificationMessage()
{
  m_type = MessageEnum::PARTYREFUSEINVITATIONNOTIFICATIONMESSAGE;
}

