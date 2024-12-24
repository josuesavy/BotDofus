#ifndef FIGHTTEAMMEMBERTAXCOLLECTORINFORMATIONS_H
#define FIGHTTEAMMEMBERTAXCOLLECTORINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/fight/FightTeamMemberInformations.h"
#include "src/utils/io/type/FuncTree.h"

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
  uint groupId;
  double uid;

private:
  void _firstNameIdFunc(Reader *input);
  void _lastNameIdFunc(Reader *input);
  void _groupIdFunc(Reader *input);
  void _uidFunc(Reader *input);
};

#endif // FIGHTTEAMMEMBERTAXCOLLECTORINFORMATIONS_H