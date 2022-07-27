#include "PartyCancelInvitationMessage.h"

void PartyCancelInvitationMessage::serialize(Writer *output)
{
  this->serializeAs_PartyCancelInvitationMessage(output);
}

void PartyCancelInvitationMessage::serializeAs_PartyCancelInvitationMessage(Writer *output)
{
  AbstractPartyMessage::serializeAs_AbstractPartyMessage(output);
  if(this->guestId < 0 || this->guestId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyCancelInvitationMessage -"<<"Forbidden value (" << this->guestId << ") on element guestId.";
  }
  output->writeVarLong((double)this->guestId);
}

void PartyCancelInvitationMessage::deserialize(Reader *input)
{
  this->deserializeAs_PartyCancelInvitationMessage(input);
}

void PartyCancelInvitationMessage::deserializeAs_PartyCancelInvitationMessage(Reader *input)
{
  AbstractPartyMessage::deserialize(input);
  this->_guestIdFunc(input);
}

void PartyCancelInvitationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyCancelInvitationMessage(tree);
}

void PartyCancelInvitationMessage::deserializeAsyncAs_PartyCancelInvitationMessage(FuncTree tree)
{
  AbstractPartyMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyCancelInvitationMessage::_guestIdFunc, this, std::placeholders::_1));
}

void PartyCancelInvitationMessage::_guestIdFunc(Reader *input)
{
  this->guestId = input->readVarUhLong();
  if(this->guestId < 0 || this->guestId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyCancelInvitationMessage -"<<"Forbidden value (" << this->guestId << ") on element of PartyCancelInvitationMessage.guestId.";
  }
}

PartyCancelInvitationMessage::PartyCancelInvitationMessage()
{
  m_type = MessageEnum::PARTYCANCELINVITATIONMESSAGE;
}

