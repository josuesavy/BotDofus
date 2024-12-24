#ifndef NAMEDPARTYTEAMWITHOUTCOME_H
#define NAMEDPARTYTEAMWITHOUTCOME_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/roleplay/party/NamedPartyTeam.h"
#include "src/utils/io/type/FuncTree.h"

class NamedPartyTeamWithOutcome : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_NamedPartyTeamWithOutcome(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_NamedPartyTeamWithOutcome(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_NamedPartyTeamWithOutcome(FuncTree tree);
  NamedPartyTeamWithOutcome();
  bool operator==(const NamedPartyTeamWithOutcome &compared);

  NamedPartyTeam team;
  uint outcome;

private:
  void _teamtreeFunc(Reader *input);
  void _outcomeFunc(Reader *input);

  FuncTree _teamtree;
};

#endif // NAMEDPARTYTEAMWITHOUTCOME_H