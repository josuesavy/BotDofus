#include "GuildListApplicationRequestMessage.h"

void GuildListApplicationRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GuildListApplicationRequestMessage(output);
}

void GuildListApplicationRequestMessage::serializeAs_GuildListApplicationRequestMessage(Writer *output)
{
  PaginationRequestAbstractMessage::serializeAs_PaginationRequestAbstractMessage(output);
}

void GuildListApplicationRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildListApplicationRequestMessage(input);
}

void GuildListApplicationRequestMessage::deserializeAs_GuildListApplicationRequestMessage(Reader *input)
{
  PaginationRequestAbstractMessage::deserialize(input);
}

void GuildListApplicationRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildListApplicationRequestMessage(tree);
}

void GuildListApplicationRequestMessage::deserializeAsyncAs_GuildListApplicationRequestMessage(FuncTree tree)
{
  PaginationRequestAbstractMessage::deserializeAsync(tree);
}

GuildListApplicationRequestMessage::GuildListApplicationRequestMessage()
{
  m_type = MessageEnum::GUILDLISTAPPLICATIONREQUESTMESSAGE;
}

