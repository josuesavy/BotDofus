#ifndef GUILDUNLOCKNEWTABACTIVITY_H
#define GUILDUNLOCKNEWTABACTIVITY_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/guild/logbook/GuildLogbookEntryBasicInformation.h"
#include "src/utils/io/type/FuncTree.h"

class GuildUnlockNewTabActivity : public GuildLogbookEntryBasicInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildUnlockNewTabActivity(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildUnlockNewTabActivity(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildUnlockNewTabActivity(FuncTree tree);
  GuildUnlockNewTabActivity();
  bool operator==(const GuildUnlockNewTabActivity &compared);
};

#endif // GUILDUNLOCKNEWTABACTIVITY_H