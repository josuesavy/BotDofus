#ifndef GAMEFIGHTCHARACTERINFORMATIONS_H
#define GAMEFIGHTCHARACTERINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/character/alignment/ActorAlignmentInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightFighterNamedInformations.h"
#include "src/protocol/types/data/game/character/status/PlayerStatus.h"
#include "src/protocol/types/data/game/context/EntityDispositionInformations.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GameFightCharacterInformations : public GameFightFighterNamedInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightCharacterInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightCharacterInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightCharacterInformations(FuncTree tree);
  GameFightCharacterInformations();
  bool operator==(const GameFightCharacterInformations &compared);

  uint level;
  ActorAlignmentInformations alignmentInfos;
  int breed;
  bool sex;

private:
  void _levelFunc(Reader *input);
  void _alignmentInfostreeFunc(Reader *input);
  void _breedFunc(Reader *input);
  void _sexFunc(Reader *input);

  FuncTree _alignmentInfostree;
};

#endif // GAMEFIGHTCHARACTERINFORMATIONS_H