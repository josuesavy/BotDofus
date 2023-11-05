#ifndef GUILDLEVELUPACTIVITY_H
#define GUILDLEVELUPACTIVITY_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/guild/logbook/GuildLogbookEntryBasicInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GuildLevelUpActivity : public GuildLogbookEntryBasicInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildLevelUpActivity(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildLevelUpActivity(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildLevelUpActivity(FuncTree tree);
  GuildLevelUpActivity();
  bool operator==(const GuildLevelUpActivity &compared);

  uint newGuildLevel;

private:
  void _newGuildLevelFunc(Reader *input);
};

#endif // GUILDLEVELUPACTIVITY_H