#include "GuildMotdSetErrorMessage.h"

void GuildMotdSetErrorMessage::serialize(Writer *output)
{
  this->serializeAs_GuildMotdSetErrorMessage(output);
}

void GuildMotdSetErrorMessage::serializeAs_GuildMotdSetErrorMessage(Writer *output)
{
  SocialNoticeSetErrorMessage::serializeAs_SocialNoticeSetErrorMessage(output);
}

void GuildMotdSetErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildMotdSetErrorMessage(input);
}

void GuildMotdSetErrorMessage::deserializeAs_GuildMotdSetErrorMessage(Reader *input)
{
  SocialNoticeSetErrorMessage::deserialize(input);
}

void GuildMotdSetErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildMotdSetErrorMessage(tree);
}

void GuildMotdSetErrorMessage::deserializeAsyncAs_GuildMotdSetErrorMessage(FuncTree tree)
{
  SocialNoticeSetErrorMessage::deserializeAsync(tree);
}

GuildMotdSetErrorMessage::GuildMotdSetErrorMessage()
{
  m_type = MessageEnum::GUILDMOTDSETERRORMESSAGE;
}

