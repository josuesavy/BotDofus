#include "AllianceInvitationMessage.h"

void AllianceInvitationMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceInvitationMessage(output);
}

void AllianceInvitationMessage::serializeAs_AllianceInvitationMessage(Writer *output)
{
  if(this->targetId < 0 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AllianceInvitationMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeVarLong((double)this->targetId);
}

void AllianceInvitationMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceInvitationMessage(input);
}

void AllianceInvitationMessage::deserializeAs_AllianceInvitationMessage(Reader *input)
{
  this->_targetIdFunc(input);
}

void AllianceInvitationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceInvitationMessage(tree);
}

void AllianceInvitationMessage::deserializeAsyncAs_AllianceInvitationMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceInvitationMessage::_targetIdFunc, this, std::placeholders::_1));
}

void AllianceInvitationMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readVarUhLong();
  if(this->targetId < 0 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AllianceInvitationMessage -"<<"Forbidden value (" << this->targetId << ") on element of AllianceInvitationMessage.targetId.";
  }
}

AllianceInvitationMessage::AllianceInvitationMessage()
{
  m_type = MessageEnum::ALLIANCEINVITATIONMESSAGE;
}

