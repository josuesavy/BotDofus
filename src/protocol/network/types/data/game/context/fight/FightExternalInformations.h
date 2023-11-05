#ifndef FIGHTEXTERNALINFORMATIONS_H
#define FIGHTEXTERNALINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class FightExternalInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightExternalInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightExternalInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightExternalInformations(FuncTree tree);
  FightExternalInformations();
  bool operator==(const FightExternalInformations &compared);

  uint fightId;
  uint fightType;
  uint fightStart;
  bool fightSpectatorLocked;
  QList<> fightTeams;
  QList<> fightTeamsOptions;

private:
  void _fightIdFunc(Reader *input);
  void _fightTypeFunc(Reader *input);
  void _fightStartFunc(Reader *input);
  void _fightSpectatorLockedFunc(Reader *input);
  void _fightTeamstreeFunc(Reader *input);
  void _fightTeamsFunc(Reader *input);
  void _fightTeamsOptionstreeFunc(Reader *input);
  void _fightTeamsOptionsFunc(Reader *input);

  FuncTree _fightTeamstree;
  uint _fightTeamsindex;
  FuncTree _fightTeamsOptionstree;
  uint _fightTeamsOptionsindex;
};

#endif // FIGHTEXTERNALINFORMATIONS_H