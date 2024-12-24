#include "GuildInvitedMessage.h"

void GuildInvitedMessage::serialize(Writer *output)
{
  this->serializeAs_GuildInvitedMessage(output);
}

void GuildInvitedMessage::serializeAs_GuildInvitedMessage(Writer *output)
{
  output->writeUTF(this->recruterName);
  this->guildInfo->serializeAs_GuildInformations(output);
}

void GuildInvitedMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildInvitedMessage(input);
}

void GuildInvitedMessage::deserializeAs_GuildInvitedMessage(Reader *input)
{
  this->_recruterNameFunc(input);
  this->guildInfo = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInfo->deserialize(input);
}

void GuildInvitedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildInvitedMessage(tree);
}

void GuildInvitedMessage::deserializeAsyncAs_GuildInvitedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildInvitedMessage::_recruterNameFunc, this, std::placeholders::_1));
  this->_guildInfotree = tree.addChild(std::bind(&GuildInvitedMessage::_guildInfotreeFunc, this, std::placeholders::_1));
}

void GuildInvitedMessage::_recruterNameFunc(Reader *input)
{
  this->recruterName = input->readUTF();
}

void GuildInvitedMessage::_guildInfotreeFunc(Reader *input)
{
  this->guildInfo = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInfo->deserializeAsync(this->_guildInfotree);
}

GuildInvitedMessage::GuildInvitedMessage()
{
  m_type = MessageEnum::GUILDINVITEDMESSAGE;
}

