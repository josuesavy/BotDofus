#include "AllianceInvitationStateRecruterMessage.h"

void AllianceInvitationStateRecruterMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceInvitationStateRecruterMessage(output);
}

void AllianceInvitationStateRecruterMessage::serializeAs_AllianceInvitationStateRecruterMessage(Writer *output)
{
  output->writeUTF(this->recrutedName);
  output->writeByte(this->invitationState);
}

void AllianceInvitationStateRecruterMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceInvitationStateRecruterMessage(input);
}

void AllianceInvitationStateRecruterMessage::deserializeAs_AllianceInvitationStateRecruterMessage(Reader *input)
{
  this->_recrutedNameFunc(input);
  this->_invitationStateFunc(input);
}

void AllianceInvitationStateRecruterMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceInvitationStateRecruterMessage(tree);
}

void AllianceInvitationStateRecruterMessage::deserializeAsyncAs_AllianceInvitationStateRecruterMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceInvitationStateRecruterMessage::_recrutedNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceInvitationStateRecruterMessage::_invitationStateFunc, this, std::placeholders::_1));
}

void AllianceInvitationStateRecruterMessage::_recrutedNameFunc(Reader *input)
{
  this->recrutedName = input->readUTF();
}

void AllianceInvitationStateRecruterMessage::_invitationStateFunc(Reader *input)
{
  this->invitationState = input->readByte();
  if(this->invitationState < 0)
  {
    qDebug()<<"ERREUR - AllianceInvitationStateRecruterMessage -"<<"Forbidden value (" << this->invitationState << ") on element of AllianceInvitationStateRecruterMessage.invitationState.";
  }
}

AllianceInvitationStateRecruterMessage::AllianceInvitationStateRecruterMessage()
{
  m_type = MessageEnum::ALLIANCEINVITATIONSTATERECRUTERMESSAGE;
}

