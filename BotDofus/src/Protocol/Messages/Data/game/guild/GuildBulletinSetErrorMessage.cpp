#include "GuildBulletinSetErrorMessage.h"

void GuildBulletinSetErrorMessage::serialize(Writer *output)
{
  this->serializeAs_GuildBulletinSetErrorMessage(output);
}

void GuildBulletinSetErrorMessage::serializeAs_GuildBulletinSetErrorMessage(Writer *output)
{
  SocialNoticeSetErrorMessage::serializeAs_SocialNoticeSetErrorMessage(output);
}

void GuildBulletinSetErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildBulletinSetErrorMessage(input);
}

void GuildBulletinSetErrorMessage::deserializeAs_GuildBulletinSetErrorMessage(Reader *input)
{
  SocialNoticeSetErrorMessage::deserialize(input);
}

void GuildBulletinSetErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildBulletinSetErrorMessage(tree);
}

void GuildBulletinSetErrorMessage::deserializeAsyncAs_GuildBulletinSetErrorMessage(FuncTree tree)
{
  SocialNoticeSetErrorMessage::deserializeAsync(tree);
}

GuildBulletinSetErrorMessage::GuildBulletinSetErrorMessage()
{
  m_type = MessageEnum::GUILDBULLETINSETERRORMESSAGE;
}

