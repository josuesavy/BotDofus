#ifndef GAMEFIGHTSHOWFIGHTERMESSAGE_H
#define GAMEFIGHTSHOWFIGHTERMESSAGE_H

#include "src/protocol/types/ClassManager.h"
#include "src/protocol/types/data/game/context/fight/GameFightFighterInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameFightShowFighterMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightShowFighterMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightShowFighterMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightShowFighterMessage(FuncTree tree);
  GameFightShowFighterMessage();

  QSharedPointer<GameFightFighterInformations> informations;

private:
  void _informationstreeFunc(Reader *input);

  FuncTree _informationstree;
};

#endif // GAMEFIGHTSHOWFIGHTERMESSAGE_H