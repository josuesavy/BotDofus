#ifndef FIGHTTEAMMEMBERTAXCOLLECTORINFORMATIONS_H
#define FIGHTTEAMMEMBERTAXCOLLECTORINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/fight/FightTeamMemberInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class FightTeamMemberTaxCollectorInformations : public FightTeamMemberInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightTeamMemberTaxCollectorInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightTeamMemberTaxCollectorInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightTeamMemberTaxCollectorInformations(FuncTree tree);
  FightTeamMemberTaxCollectorInformations();
  bool operator==(const FightTeamMemberTaxCollectorInformations &compared);

  uint firstNameId;
  uint lastNameId;
  uint level;
  uint guildId;
  double uid;

private:
  void _firstNameIdFunc(Reader *input);
  void _lastNameIdFunc(Reader *input);
  void _levelFunc(Reader *input);
  void _guildIdFunc(Reader *input);
  void _uidFunc(Reader *input);
};

#endif // FIGHTTEAMMEMBERTAXCOLLECTORINFORMATIONS_H