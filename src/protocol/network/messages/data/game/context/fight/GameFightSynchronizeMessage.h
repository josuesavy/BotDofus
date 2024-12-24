#ifndef GAMEFIGHTSYNCHRONIZEMESSAGE_H
#define GAMEFIGHTSYNCHRONIZEMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/context/fight/GameFightFighterInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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