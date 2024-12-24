#include "GuildInvitationStateRecrutedMessage.h"

void GuildInvitationStateRecrutedMessage::serialize(Writer *output)
{
  this->serializeAs_GuildInvitationStateRecrutedMessage(output);
}

void GuildInvitationStateRecrutedMessage::serializeAs_GuildInvitationStateRecrutedMessage(Writer *output)
{
  output->writeByte(this->invitationState);
}

void GuildInvitationStateRecrutedMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildInvitationStateRecrutedMessage(input);
}

void GuildInvitationStateRecrutedMessage::deserializeAs_GuildInvitationStateRecrutedMessage(Reader *input)
{
  this->_invitationStateFunc(input);
}

void GuildInvitationStateRecrutedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildInvitationStateRecrutedMessage(tree);
}

void GuildInvitationStateRecrutedMessage::deserializeAsyncAs_GuildInvitationStateRecrutedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildInvitationStateRecrutedMessage::_invitationStateFunc, this, std::placeholders::_1));
}

void GuildInvitationStateRecrutedMessage::_invitationStateFunc(Reader *input)
{
  this->invitationState = input->readByte();
  if(this->invitationState < 0)
  {
    qDebug()<<"ERREUR - GuildInvitationStateRecrutedMessage -"<<"Forbidden value (" << this->invitationState << ") on element of GuildInvitationStateRecrutedMessage.invitationState.";
  }
}

GuildInvitationStateRecrutedMessage::GuildInvitationStateRecrutedMessage()
{
  m_type = MessageEnum::GUILDINVITATIONSTATERECRUTEDMESSAGE;
}

