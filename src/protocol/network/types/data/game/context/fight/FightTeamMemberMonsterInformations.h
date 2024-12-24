#ifndef FIGHTTEAMMEMBERMONSTERINFORMATIONS_H
#define FIGHTTEAMMEMBERMONSTERINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/fight/FightTeamMemberInformations.h"
#include "src/utils/io/type/FuncTree.h"

class FightTeamMemberMonsterInformations : public FightTeamMemberInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightTeamMemberMonsterInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightTeamMemberMonsterInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightTeamMemberMonsterInformations(FuncTree tree);
  FightTeamMemberMonsterInformations();
  bool operator==(const FightTeamMemberMonsterInformations &compared);

  int monsterId;
  uint grade;

private:
  void _monsterIdFunc(Reader *input);
  void _gradeFunc(Reader *input);
};

#endif // FIGHTTEAMMEMBERMONSTERINFORMATIONS_H