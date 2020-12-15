#ifndef GAMEFIGHTMINIMALSTATSPREPARATION_H
#define GAMEFIGHTMINIMALSTATSPREPARATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/fight/GameFightMinimalStats.h"
#include "src/engines/io/network/utils/FuncTree.h"

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