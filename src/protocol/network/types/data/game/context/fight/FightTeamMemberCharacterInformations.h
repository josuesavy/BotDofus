#ifndef FIGHTTEAMMEMBERCHARACTERINFORMATIONS_H
#define FIGHTTEAMMEMBERCHARACTERINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/fight/FightTeamMemberInformations.h"
#include "src/utils/io/type/FuncTree.h"

class FightTeamMemberCharacterInformations : public FightTeamMemberInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightTeamMemberCharacterInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightTeamMemberCharacterInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightTeamMemberCharacterInformations(FuncTree tree);
  FightTeamMemberCharacterInformations();
  bool operator==(const FightTeamMemberCharacterInformations &compared);

  QString name;
  uint level;

private:
  void _nameFunc(Reader *input);
  void _levelFunc(Reader *input);
};

#endif // FIGHTTEAMMEMBERCHARACTERINFORMATIONS_H