#ifndef FIGHTTEAMMEMBERINFORMATIONS_H
#define FIGHTTEAMMEMBERINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class FightTeamMemberInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightTeamMemberInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightTeamMemberInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightTeamMemberInformations(FuncTree tree);
  FightTeamMemberInformations();
  bool operator==(const FightTeamMemberInformations &compared);

  double id;

private:
  void _idFunc(Reader *input);
};

#endif // FIGHTTEAMMEMBERINFORMATIONS_H