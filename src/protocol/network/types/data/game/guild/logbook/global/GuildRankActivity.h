#ifndef GUILDRANKACTIVITY_H
#define GUILDRANKACTIVITY_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/rank/RankMinimalInformation.h"
#include "src/protocol/types/data/game/guild/logbook/GuildLogbookEntryBasicInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GuildRankActivity : public GuildLogbookEntryBasicInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildRankActivity(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildRankActivity(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildRankActivity(FuncTree tree);
  GuildRankActivity();
  bool operator==(const GuildRankActivity &compared);

  uint rankActivityType;
  RankMinimalInformation guildRankMinimalInfos;

private:
  void _rankActivityTypeFunc(Reader *input);
  void _guildRankMinimalInfostreeFunc(Reader *input);

  FuncTree _guildRankMinimalInfostree;
};

#endif // GUILDRANKACTIVITY_H