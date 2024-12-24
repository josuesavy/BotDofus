#include "GuildBulletinMessage.h"

void GuildBulletinMessage::serialize(Writer *output)
{
  this->serializeAs_GuildBulletinMessage(output);
}

void GuildBulletinMessage::serializeAs_GuildBulletinMessage(Writer *output)
{
  BulletinMessage::serializeAs_BulletinMessage(output);
}

void GuildBulletinMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildBulletinMessage(input);
}

void GuildBulletinMessage::deserializeAs_GuildBulletinMessage(Reader *input)
{
  BulletinMessage::deserialize(input);
}

void GuildBulletinMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildBulletinMessage(tree);
}

void GuildBulletinMessage::deserializeAsyncAs_GuildBulletinMessage(FuncTree tree)
{
  BulletinMessage::deserializeAsync(tree);
}

GuildBulletinMessage::GuildBulletinMessage()
{
  m_type = MessageEnum::GUILDBULLETINMESSAGE;
}

