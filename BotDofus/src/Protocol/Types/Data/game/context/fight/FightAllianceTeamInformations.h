#ifndef FIGHTALLIANCETEAMINFORMATIONS_H
#define FIGHTALLIANCETEAMINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/fight/FightTeamInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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