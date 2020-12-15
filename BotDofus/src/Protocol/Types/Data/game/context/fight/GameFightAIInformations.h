#ifndef GAMEFIGHTAIINFORMATIONS_H
#define GAMEFIGHTAIINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/fight/GameFightFighterInformations.h"
#include "src/protocol/types/data/game/context/EntityDispositionInformations.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GameFightAIInformations : public GameFightFighterInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightAIInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightAIInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightAIInformations(FuncTree tree);
  GameFightAIInformations();
  bool operator==(const GameFightAIInformations &compared);
};

#endif // GAMEFIGHTAIINFORMATIONS_H