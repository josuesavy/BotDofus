#ifndef FIGHTTEAMINFORMATIONS_H
#define FIGHTTEAMINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/fight/FightTeamMemberInformations.h"
#include "src/protocol/network/types/data/game/context/fight/AbstractFightTeamInformations.h"
#include "src/protocol/network/types/ClassManager.h"
#include "src/utils/io/type/FuncTree.h"

class FightTeamInformations : public AbstractFightTeamInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightTeamInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightTeamInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightTeamInformations(FuncTree tree);
  FightTeamInformations();
  bool operator==(const FightTeamInformations &compared);

  QList<QSharedPointer<FightTeamMemberInformations>> teamMembers;

private:
  void _teamMemberstreeFunc(Reader *input);
  void _teamMembersFunc(Reader *input);

  FuncTree _teamMemberstree;
};

#endif // FIGHTTEAMINFORMATIONS_H