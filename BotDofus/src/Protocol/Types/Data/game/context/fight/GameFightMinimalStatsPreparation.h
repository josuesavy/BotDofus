#ifndef GAMEFIGHTMINIMALSTATSPREPARATION_H
#define GAMEFIGHTMINIMALSTATSPREPARATION_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightMinimalStats.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class GameFightMinimalStatsPreparation : public GameFightMinimalStats
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightMinimalStatsPreparation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightMinimalStatsPreparation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightMinimalStatsPreparation(FuncTree tree);
  GameFightMinimalStatsPreparation();
  bool operator==(const GameFightMinimalStatsPreparation &compared);

  uint initiative;

private:
  void _initiativeFunc(Reader *input);
};

#endif // GAMEFIGHTMINIMALSTATSPREPARATION_H