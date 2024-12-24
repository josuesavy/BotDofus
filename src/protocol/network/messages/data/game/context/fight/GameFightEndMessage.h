#ifndef GAMEFIGHTENDMESSAGE_H
#define GAMEFIGHTENDMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/context/fight/FightResultListEntry.h"
#include "src/protocol/network/types/data/game/context/roleplay/party/NamedPartyTeamWithOutcome.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameFightEndMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightEndMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightEndMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightEndMessage(FuncTree tree);
  GameFightEndMessage();

  uint duration;
  int rewardRate;
  int lootShareLimitMalus;
  QList<QSharedPointer<FightResultListEntry>> results;
  QList<NamedPartyTeamWithOutcome> namedPartyTeamsOutcomes;

private:
  void _durationFunc(Reader *input);
  void _rewardRateFunc(Reader *input);
  void _lootShareLimitMalusFunc(Reader *input);
  void _resultstreeFunc(Reader *input);
  void _resultsFunc(Reader *input);
  void _namedPartyTeamsOutcomestreeFunc(Reader *input);
  void _namedPartyTeamsOutcomesFunc(Reader *input);

  FuncTree _resultstree;
  FuncTree _namedPartyTeamsOutcomestree;
};

#endif // GAMEFIGHTENDMESSAGE_H