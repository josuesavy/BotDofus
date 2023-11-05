#ifndef GAMEFIGHTREFRESHFIGHTERMESSAGE_H
#define GAMEFIGHTREFRESHFIGHTERMESSAGE_H

#include "src/protocol/types/ClassManager.h"
#include "src/protocol/types/data/game/context/GameContextActorInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameFightRefreshFighterMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightRefreshFighterMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightRefreshFighterMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightRefreshFighterMessage(FuncTree tree);
  GameFightRefreshFighterMessage();

  QSharedPointer<GameContextActorInformations> informations;

private:
  void _informationstreeFunc(Reader *input);

  FuncTree _informationstree;
};

#endif // GAMEFIGHTREFRESHFIGHTERMESSAGE_H