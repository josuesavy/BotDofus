#ifndef FIGHTTEAMMEMBERWITHALLIANCECHARACTERINFORMATIONS_H
#define FIGHTTEAMMEMBERWITHALLIANCECHARACTERINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/BasicAllianceInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/FightTeamMemberCharacterInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class FightTeamMemberWithAllianceCharacterInformations : public FightTeamMemberCharacterInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightTeamMemberWithAllianceCharacterInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightTeamMemberWithAllianceCharacterInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightTeamMemberWithAllianceCharacterInformations(FuncTree tree);
  FightTeamMemberWithAllianceCharacterInformations();
  bool operator==(const FightTeamMemberWithAllianceCharacterInformations &compared);

  QSharedPointer<BasicAllianceInformations> allianceInfos;

private:
  void _allianceInfostreeFunc(Reader *input);

  FuncTree _allianceInfostree;
};

#endif // FIGHTTEAMMEMBERWITHALLIANCECHARACTERINFORMATIONS_H