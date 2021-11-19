#include "GuildLeftMessage.h"

void GuildLeftMessage::serialize(Writer *output)
{
}

void GuildLeftMessage::serializeAs_GuildLeftMessage(Writer *output)
{
}

void GuildLeftMessage::deserialize(Reader *input)
{
}

void GuildLeftMessage::deserializeAs_GuildLeftMessage(Reader *input)
{
}

void GuildLeftMessage::deserializeAsync(FuncTree tree)
{
}

void GuildLeftMessage::deserializeAsyncAs_GuildLeftMessage(FuncTree tree)
{
}

GuildLeftMessage::GuildLeftMessage()
{
  m_type = MessageEnum::GUILDLEFTMESSAGE;
}

