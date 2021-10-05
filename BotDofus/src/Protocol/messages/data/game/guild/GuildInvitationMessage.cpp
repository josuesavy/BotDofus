#include "GuildInvitationMessage.h"

void GuildInvitationMessage::serialize(Writer *output)
{
  this->serializeAs_GuildInvitationMessage(output);
}

void GuildInvitationMessage::serializeAs_GuildInvitationMessage(Writer *output)
{
  if(this->targetId < 0 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildInvitationMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeVarLong((double)this->targetId);
}

void GuildInvitationMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildInvitationMessage(input);
}

void GuildInvitationMessage::deserializeAs_GuildInvitationMessage(Reader *input)
{
  this->_targetIdFunc(input);
}

void GuildInvitationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildInvitationMessage(tree);
}

void GuildInvitationMessage::deserializeAsyncAs_GuildInvitationMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildInvitationMessage::_targetIdFunc, this, std::placeholders::_1));
}

void GuildInvitationMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readVarUhLong();
  if(this->targetId < 0 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildInvitationMessage -"<<"Forbidden value (" << this->targetId << ") on element of GuildInvitationMessage.targetId.";
  }
}

GuildInvitationMessage::GuildInvitationMessage()
{
  m_type = MessageEnum::GUILDINVITATIONMESSAGE;
}

