#ifndef GAMEACTIONFIGHTMULTIPLESUMMONMESSAGE_H
#define GAMEACTIONFIGHTMULTIPLESUMMONMESSAGE_H

#include "src/Protocol/Types/Data/game/context/fight/GameContextSummonsInformation.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightMultipleSummonMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightMultipleSummonMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightMultipleSummonMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightMultipleSummonMessage(FuncTree tree);
  GameActionFightMultipleSummonMessage();

  QList<QSharedPointer<GameContextSummonsInformation>> summons;

private:
  void _summonstreeFunc(Reader *input);
  void _summonsFunc(Reader *input);

  FuncTree _summonstree;
};

#endif // GAMEACTIONFIGHTMULTIPLESUMMONMESSAGE_H