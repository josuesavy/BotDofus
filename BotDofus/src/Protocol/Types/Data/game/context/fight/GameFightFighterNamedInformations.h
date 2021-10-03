#ifndef GAMEFIGHTFIGHTERNAMEDINFORMATIONS_H
#define GAMEFIGHTFIGHTERNAMEDINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/character/status/PlayerStatus.h"
#include "src/protocol/types/data/game/context/fight/GameFightFighterInformations.h"
#include "src/protocol/types/data/game/context/EntityDispositionInformations.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GameFightFighterNamedInformations : public GameFightFighterInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightFighterNamedInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightFighterNamedInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightFighterNamedInformations(FuncTree tree);
  GameFightFighterNamedInformations();
  bool operator==(const GameFightFighterNamedInformations &compared);

  QString name;
  QSharedPointer<PlayerStatus> status;
  int leagueId;
  int ladderPosition;
  bool hiddenInPrefight;

private:
  void _nameFunc(Reader *input);
  void _statustreeFunc(Reader *input);
  void _leagueIdFunc(Reader *input);
  void _ladderPositionFunc(Reader *input);
  void _hiddenInPrefightFunc(Reader *input);

  FuncTree _statustree;
};

#endif // GAMEFIGHTFIGHTERNAMEDINFORMATIONS_H