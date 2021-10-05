#include "PartyInvitationCancelledForGuestMessage.h"

void PartyInvitationCancelledForGuestMessage::serialize(Writer *output)
{
  this->serializeAs_PartyInvitationCancelledForGuestMessage(output);
}

void PartyInvitationCancelledForGuestMessage::serializeAs_PartyInvitationCancelledForGuestMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
  if(this->cancelerId < 0 || this->cancelerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyInvitationCancelledForGuestMessage -"<<"Forbidden value (" << this->cancelerId << ") on element cancelerId.";
  }
  output->writeVarLong((double)this->cancelerId);
}

void PartyInvitationCancelledForGuestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyInvitationCancelledForGuestMessage(input);
}

void PartyInvitationCancelledForGuestMessage::deserializeAs_PartyInvitationCancelledForGuestMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
  this->_cancelerIdFunc(input);
}

void PartyInvitationCancelledForGuestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyInvitationCancelledForGuestMessage(tree);
}

void PartyInvitationCancelledForGuestMessage::deserializeAsyncAs_PartyInvitationCancelledForGuestMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyInvitationCancelledForGuestMessage::_cancelerIdFunc, this, std::placeholders::_1));
}

void PartyInvitationCancelledForGuestMessage::_cancelerIdFunc(Reader *input)
{
  this->cancelerId = input->readVarUhLong();
  if(this->cancelerId < 0 || this->cancelerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyInvitationCancelledForGuestMessage -"<<"Forbidden value (" << this->cancelerId << ") on element of PartyInvitationCancelledForGuestMessage.cancelerId.";
  }
}

PartyInvitationCancelledForGuestMessage::PartyInvitationCancelledForGuestMessage()
{
  m_type = MessageEnum::PARTYINVITATIONCANCELLEDFORGUESTMESSAGE;
}

