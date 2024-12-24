#include "GuildUnlockNewTabActivity.h"

void GuildUnlockNewTabActivity::serialize(Writer *output)
{
  this->serializeAs_GuildUnlockNewTabActivity(output);
}

void GuildUnlockNewTabActivity::serializeAs_GuildUnlockNewTabActivity(Writer *output)
{
  GuildLogbookEntryBasicInformation::serializeAs_GuildLogbookEntryBasicInformation(output);
}

void GuildUnlockNewTabActivity::deserialize(Reader *input)
{
  this->deserializeAs_GuildUnlockNewTabActivity(input);
}

void GuildUnlockNewTabActivity::deserializeAs_GuildUnlockNewTabActivity(Reader *input)
{
  GuildLogbookEntryBasicInformation::deserialize(input);
}

void GuildUnlockNewTabActivity::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildUnlockNewTabActivity(tree);
}

void GuildUnlockNewTabActivity::deserializeAsyncAs_GuildUnlockNewTabActivity(FuncTree tree)
{
  GuildLogbookEntryBasicInformation::deserializeAsync(tree);
}

GuildUnlockNewTabActivity::GuildUnlockNewTabActivity()
{
  m_types<<ClassEnum::GUILDUNLOCKNEWTABACTIVITY;
}

bool GuildUnlockNewTabActivity::operator==(const GuildUnlockNewTabActivity &compared)
{
  return true;
}

