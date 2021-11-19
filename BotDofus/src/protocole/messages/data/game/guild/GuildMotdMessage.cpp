#include "GuildMotdMessage.h"

void GuildMotdMessage::serialize(Writer *output)
{
  this->serializeAs_GuildMotdMessage(output);
}

void GuildMotdMessage::serializeAs_GuildMotdMessage(Writer *output)
{
  SocialNoticeMessage::serializeAs_SocialNoticeMessage(output);
}

void GuildMotdMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildMotdMessage(input);
}

void GuildMotdMessage::deserializeAs_GuildMotdMessage(Reader *input)
{
  SocialNoticeMessage::deserialize(input);
}

void GuildMotdMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildMotdMessage(tree);
}

void GuildMotdMessage::deserializeAsyncAs_GuildMotdMessage(FuncTree tree)
{
  SocialNoticeMessage::deserializeAsync(tree);
}

GuildMotdMessage::GuildMotdMessage()
{
  m_type = MessageEnum::GUILDMOTDMESSAGE;
}

