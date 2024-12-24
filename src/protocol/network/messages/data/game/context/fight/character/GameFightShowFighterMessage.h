#ifndef GAMEFIGHTSHOWFIGHTERMESSAGE_H
#define GAMEFIGHTSHOWFIGHTERMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/context/fight/GameFightFighterInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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