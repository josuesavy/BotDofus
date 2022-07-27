#include "GuildMembershipMessage.h"

void GuildMembershipMessage::serialize(Writer *output)
{
  this->serializeAs_GuildMembershipMessage(output);
}

void GuildMembershipMessage::serializeAs_GuildMembershipMessage(Writer *output)
{
  GuildJoinedMessage::serializeAs_GuildJoinedMessage(output);
}

void GuildMembershipMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildMembershipMessage(input);
}

void GuildMembershipMessage::deserializeAs_GuildMembershipMessage(Reader *input)
{
  GuildJoinedMessage::deserialize(input);
}

void GuildMembershipMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildMembershipMessage(tree);
}

void GuildMembershipMessage::deserializeAsyncAs_GuildMembershipMessage(FuncTree tree)
{
  GuildJoinedMessage::deserializeAsync(tree);
}

GuildMembershipMessage::GuildMembershipMessage()
{
  m_type = MessageEnum::GUILDMEMBERSHIPMESSAGE;
}

