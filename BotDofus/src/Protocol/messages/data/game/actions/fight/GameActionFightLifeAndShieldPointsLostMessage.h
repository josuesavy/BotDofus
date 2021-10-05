#ifndef GAMEACTIONFIGHTLIFEANDSHIELDPOINTSLOSTMESSAGE_H
#define GAMEACTIONFIGHTLIFEANDSHIELDPOINTSLOSTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/actions/fight/GameActionFightLifePointsLostMessage.h"

class GameActionFightLifeAndShieldPointsLostMessage : public GameActionFightLifePointsLostMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightLifeAndShieldPointsLostMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightLifeAndShieldPointsLostMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightLifeAndShieldPointsLostMessage(FuncTree tree);
  GameActionFightLifeAndShieldPointsLostMessage();

  uint shieldLoss;

private:
  void _shieldLossFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTLIFEANDSHIELDPOINTSLOSTMESSAGE_H