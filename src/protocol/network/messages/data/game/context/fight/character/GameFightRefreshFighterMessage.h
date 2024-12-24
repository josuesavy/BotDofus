#ifndef GAMEFIGHTREFRESHFIGHTERMESSAGE_H
#define GAMEFIGHTREFRESHFIGHTERMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/context/GameContextActorInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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