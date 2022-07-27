#ifndef GUILDUNLOCKNEWTABACTIVITY_H
#define GUILDUNLOCKNEWTABACTIVITY_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/guild/logbook/GuildLogbookEntryBasicInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"

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