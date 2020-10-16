#ifndef BREACHGAMEFIGHTENDMESSAGE_H
#define BREACHGAMEFIGHTENDMESSAGE_H

#include "src/Protocol/Types/Data/game/context/fight/FightResultListEntry.h"
#include "src/Protocol/Types/Data/game/context/roleplay/party/NamedPartyTeamWithOutcome.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/fight/GameFightEndMessage.h"

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