#ifndef FIGHTTEAMMEMBERENTITYINFORMATION_H
#define FIGHTTEAMMEMBERENTITYINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/fight/FightTeamMemberInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class FightTeamMemberEntityInformation : public FightTeamMemberInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightTeamMemberEntityInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightTeamMemberEntityInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightTeamMemberEntityInformation(FuncTree tree);
  FightTeamMemberEntityInformation();
  bool operator==(const FightTeamMemberEntityInformation &compared);

  uint entityModelId;
  uint level;
  double masterId;

private:
  void _entityModelIdFunc(Reader *input);
  void _levelFunc(Reader *input);
  void _masterIdFunc(Reader *input);
};

#endif // FIGHTTEAMMEMBERENTITYINFORMATION_H