#include "GuildInvitationStateRecruterMessage.h"

void GuildInvitationStateRecruterMessage::serialize(Writer *output)
{
  this->serializeAs_GuildInvitationStateRecruterMessage(output);
}

void GuildInvitationStateRecruterMessage::serializeAs_GuildInvitationStateRecruterMessage(Writer *output)
{
  output->writeUTF(this->recrutedName);
  output->writeByte(this->invitationState);
}

void GuildInvitationStateRecruterMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildInvitationStateRecruterMessage(input);
}

void GuildInvitationStateRecruterMessage::deserializeAs_GuildInvitationStateRecruterMessage(Reader *input)
{
  this->_recrutedNameFunc(input);
  this->_invitationStateFunc(input);
}

void GuildInvitationStateRecruterMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildInvitationStateRecruterMessage(tree);
}

void GuildInvitationStateRecruterMessage::deserializeAsyncAs_GuildInvitationStateRecruterMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildInvitationStateRecruterMessage::_recrutedNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildInvitationStateRecruterMessage::_invitationStateFunc, this, std::placeholders::_1));
}

void GuildInvitationStateRecruterMessage::_recrutedNameFunc(Reader *input)
{
  this->recrutedName = input->readUTF();
}

void GuildInvitationStateRecruterMessage::_invitationStateFunc(Reader *input)
{
  this->invitationState = input->readByte();
  if(this->invitationState < 0)
  {
    qDebug()<<"ERREUR - GuildInvitationStateRecruterMessage -"<<"Forbidden value (" << this->invitationState << ") on element of GuildInvitationStateRecruterMessage.invitationState.";
  }
}

GuildInvitationStateRecruterMessage::GuildInvitationStateRecruterMessage()
{
  m_type = MessageEnum::GUILDINVITATIONSTATERECRUTERMESSAGE;
}

