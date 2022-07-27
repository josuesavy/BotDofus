#ifndef GUILDPLAYERRANKUPDATEACTIVITY_H
#define GUILDPLAYERRANKUPDATEACTIVITY_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/guild/GuildRankMinimalInformation.h"
#include "src/protocol/types/data/game/guild/logbook/GuildLogbookEntryBasicInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GuildPlayerRankUpdateActivity : public GuildLogbookEntryBasicInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildPlayerRankUpdateActivity(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildPlayerRankUpdateActivity(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildPlayerRankUpdateActivity(FuncTree tree);
  GuildPlayerRankUpdateActivity();
  bool operator==(const GuildPlayerRankUpdateActivity &compared);

  GuildRankMinimalInformation guildRankMinimalInfos;
  double sourcePlayerId;
  double targetPlayerId;
  QString sourcePlayerName;
  QString targetPlayerName;

private:
  void _guildRankMinimalInfostreeFunc(Reader *input);
  void _sourcePlayerIdFunc(Reader *input);
  void _targetPlayerIdFunc(Reader *input);
  void _sourcePlayerNameFunc(Reader *input);
  void _targetPlayerNameFunc(Reader *input);

  FuncTree _guildRankMinimalInfostree;
};

#endif // GUILDPLAYERRANKUPDATEACTIVITY_H