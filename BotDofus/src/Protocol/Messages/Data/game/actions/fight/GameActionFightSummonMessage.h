#ifndef GAMEACTIONFIGHTSUMMONMESSAGE_H
#define GAMEACTIONFIGHTSUMMONMESSAGE_H

#include "src/Protocol/Types/Data/game/context/fight/GameFightFighterInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightSummonMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightSummonMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightSummonMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightSummonMessage(FuncTree tree);
  GameActionFightSummonMessage();

  QList<QSharedPointer<GameFightFighterInformations>> summons;

private:
  void _summonstreeFunc(Reader *input);
  void _summonsFunc(Reader *input);

  FuncTree _summonstree;
};

#endif // GAMEACTIONFIGHTSUMMONMESSAGE_H