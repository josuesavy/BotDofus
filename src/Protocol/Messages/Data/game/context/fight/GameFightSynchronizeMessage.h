#ifndef GAMEFIGHTSYNCHRONIZEMESSAGE_H
#define GAMEFIGHTSYNCHRONIZEMESSAGE_H

#include "src/Protocol/Types/Data/game/context/fight/GameFightFighterInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameFightSynchronizeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightSynchronizeMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightSynchronizeMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightSynchronizeMessage(FuncTree tree);
  GameFightSynchronizeMessage();

  QList<QSharedPointer<GameFightFighterInformations>> fighters;

private:
  void _fighterstreeFunc(Reader *input);
  void _fightersFunc(Reader *input);

  FuncTree _fighterstree;
};

#endif // GAMEFIGHTSYNCHRONIZEMESSAGE_H