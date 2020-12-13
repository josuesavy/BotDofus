#ifndef BREACHGAMEFIGHTENDMESSAGE_H
#define BREACHGAMEFIGHTENDMESSAGE_H

#include "src/protocol/types/data/game/context/fight/FightResultListEntry.h"
#include "src/protocol/types/data/game/context/roleplay/party/NamedPartyTeamWithOutcome.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/fight/GameFightEndMessage.h"

class BreachGameFightEndMessage : public GameFightEndMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachGameFightEndMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachGameFightEndMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachGameFightEndMessage(FuncTree tree);
  BreachGameFightEndMessage();

  int budget;

private:
  void _budgetFunc(Reader *input);
};

#endif // BREACHGAMEFIGHTENDMESSAGE_H