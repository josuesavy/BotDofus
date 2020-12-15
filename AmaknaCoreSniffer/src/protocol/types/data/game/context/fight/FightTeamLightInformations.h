#ifndef FIGHTTEAMLIGHTINFORMATIONS_H
#define FIGHTTEAMLIGHTINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/fight/AbstractFightTeamInformations.h"
#include "src/engines/io/network/utils/BooleanByteWrapper.h"
#include "src/engines/io/network/utils/FuncTree.h"

class FightTeamLightInformations : public AbstractFightTeamInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightTeamLightInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightTeamLightInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightTeamLightInformations(FuncTree tree);
  FightTeamLightInformations();
  bool operator==(const FightTeamLightInformations &compared);

  uint teamMembersCount;
  uint meanLevel;
  bool hasFriend;
  bool hasGuildMember;
  bool hasAllianceMember;
  bool hasGroupMember;
  bool hasMyTaxCollector;

private:
  void deserializeByteBoxes(Reader *input);
  void _teamMembersCountFunc(Reader *input);
  void _meanLevelFunc(Reader *input);
};

#endif // FIGHTTEAMLIGHTINFORMATIONS_H