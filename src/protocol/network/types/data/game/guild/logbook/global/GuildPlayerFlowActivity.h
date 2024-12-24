#ifndef GUILDPLAYERFLOWACTIVITY_H
#define GUILDPLAYERFLOWACTIVITY_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/guild/logbook/GuildLogbookEntryBasicInformation.h"
#include "src/utils/io/type/FuncTree.h"

class GuildPlayerFlowActivity : public GuildLogbookEntryBasicInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildPlayerFlowActivity(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildPlayerFlowActivity(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildPlayerFlowActivity(FuncTree tree);
  GuildPlayerFlowActivity();
  bool operator==(const GuildPlayerFlowActivity &compared);

  double playerId;
  QString playerName;
  uint playerFlowEventType;

private:
  void _playerIdFunc(Reader *input);
  void _playerNameFunc(Reader *input);
  void _playerFlowEventTypeFunc(Reader *input);
};

#endif // GUILDPLAYERFLOWACTIVITY_H