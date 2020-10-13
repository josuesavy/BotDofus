#ifndef FIGHTCOMMONINFORMATIONS_H
#define FIGHTCOMMONINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/fight/FightTeamInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/FightOptionsInformations.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class FightCommonInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightCommonInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightCommonInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightCommonInformations(FuncTree tree);
  FightCommonInformations();
  bool operator==(const FightCommonInformations &compared);

  uint fightId;
  uint fightType;
  QList<QSharedPointer<FightTeamInformations>> fightTeams;
  QList<uint> fightTeamsPositions;
  QList<FightOptionsInformations> fightTeamsOptions;

private:
  void _fightIdFunc(Reader *input);
  void _fightTypeFunc(Reader *input);
  void _fightTeamstreeFunc(Reader *input);
  void _fightTeamsFunc(Reader *input);
  void _fightTeamsPositionstreeFunc(Reader *input);
  void _fightTeamsPositionsFunc(Reader *input);
  void _fightTeamsOptionstreeFunc(Reader *input);
  void _fightTeamsOptionsFunc(Reader *input);

  FuncTree _fightTeamstree;
  FuncTree _fightTeamsPositionstree;
  FuncTree _fightTeamsOptionstree;
};

#endif // FIGHTCOMMONINFORMATIONS_H