#include "GuildInvitationByNameMessage.h"

void GuildInvitationByNameMessage::serialize(Writer *output)
{
  this->serializeAs_GuildInvitationByNameMessage(output);
}

void GuildInvitationByNameMessage::serializeAs_GuildInvitationByNameMessage(Writer *output)
{
  output->writeUTF(this->name);
}

void GuildInvitationByNameMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildInvitationByNameMessage(input);
}

void GuildInvitationByNameMessage::deserializeAs_GuildInvitationByNameMessage(Reader *input)
{
  this->_nameFunc(input);
}

void GuildInvitationByNameMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildInvitationByNameMessage(tree);
}

void GuildInvitationByNameMessage::deserializeAsyncAs_GuildInvitationByNameMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildInvitationByNameMessage::_nameFunc, this, std::placeholders::_1));
}

void GuildInvitationByNameMessage::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

GuildInvitationByNameMessage::GuildInvitationByNameMessage()
{
  m_type = MessageEnum::GUILDINVITATIONBYNAMEMESSAGE;
}

