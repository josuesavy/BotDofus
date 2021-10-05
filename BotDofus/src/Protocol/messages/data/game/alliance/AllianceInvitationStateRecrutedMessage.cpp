#include "AllianceInvitationStateRecrutedMessage.h"

void AllianceInvitationStateRecrutedMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceInvitationStateRecrutedMessage(output);
}

void AllianceInvitationStateRecrutedMessage::serializeAs_AllianceInvitationStateRecrutedMessage(Writer *output)
{
  output->writeByte(this->invitationState);
}

void AllianceInvitationStateRecrutedMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceInvitationStateRecrutedMessage(input);
}

void AllianceInvitationStateRecrutedMessage::deserializeAs_AllianceInvitationStateRecrutedMessage(Reader *input)
{
  this->_invitationStateFunc(input);
}

void AllianceInvitationStateRecrutedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceInvitationStateRecrutedMessage(tree);
}

void AllianceInvitationStateRecrutedMessage::deserializeAsyncAs_AllianceInvitationStateRecrutedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceInvitationStateRecrutedMessage::_invitationStateFunc, this, std::placeholders::_1));
}

void AllianceInvitationStateRecrutedMessage::_invitationStateFunc(Reader *input)
{
  this->invitationState = input->readByte();
  if(this->invitationState < 0)
  {
    qDebug()<<"ERREUR - AllianceInvitationStateRecrutedMessage -"<<"Forbidden value (" << this->invitationState << ") on element of AllianceInvitationStateRecrutedMessage.invitationState.";
  }
}

AllianceInvitationStateRecrutedMessage::AllianceInvitationStateRecrutedMessage()
{
  m_type = MessageEnum::ALLIANCEINVITATIONSTATERECRUTEDMESSAGE;
}

