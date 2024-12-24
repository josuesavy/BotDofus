#ifndef GAMEFIGHTSHOWFIGHTERRANDOMSTATICPOSEMESSAGE_H
#define GAMEFIGHTSHOWFIGHTERRANDOMSTATICPOSEMESSAGE_H

#include "src/protocol/network/types/data/game/context/fight/GameFightFighterInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/context/fight/character/GameFightShowFighterMessage.h"

class GameFightShowFighterRandomStaticPoseMessage : public GameFightShowFighterMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightShowFighterRandomStaticPoseMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightShowFighterRandomStaticPoseMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightShowFighterRandomStaticPoseMessage(FuncTree tree);
  GameFightShowFighterRandomStaticPoseMessage();
};

#endif // GAMEFIGHTSHOWFIGHTERRANDOMSTATICPOSEMESSAGE_H