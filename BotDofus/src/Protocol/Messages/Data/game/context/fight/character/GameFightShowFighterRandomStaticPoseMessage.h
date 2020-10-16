#ifndef GAMEFIGHTSHOWFIGHTERRANDOMSTATICPOSEMESSAGE_H
#define GAMEFIGHTSHOWFIGHTERRANDOMSTATICPOSEMESSAGE_H

#include "src/Protocol/Types/Data/game/context/fight/GameFightFighterInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/fight/character/GameFightShowFighterMessage.h"

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