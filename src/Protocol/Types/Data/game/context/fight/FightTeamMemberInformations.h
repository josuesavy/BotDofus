#ifndef FIGHTTEAMMEMBERINFORMATIONS_H
#define FIGHTTEAMMEMBERINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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