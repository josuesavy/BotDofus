#ifndef FIGHTALLIANCETEAMINFORMATIONS_H
#define FIGHTALLIANCETEAMINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/fight/FightTeamInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class FightAllianceTeamInformations : public FightTeamInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightAllianceTeamInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightAllianceTeamInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightAllianceTeamInformations(FuncTree tree);
  FightAllianceTeamInformations();
  bool operator==(const FightAllianceTeamInformations &compared);

  uint relation;

private:
  void _relationFunc(Reader *input);
};

#endif // FIGHTALLIANCETEAMINFORMATIONS_H