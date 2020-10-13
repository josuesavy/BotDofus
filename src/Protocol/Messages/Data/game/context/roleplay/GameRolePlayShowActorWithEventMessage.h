#ifndef GAMEROLEPLAYSHOWACTORWITHEVENTMESSAGE_H
#define GAMEROLEPLAYSHOWACTORWITHEVENTMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/GameRolePlayShowActorMessage.h"

class GameRolePlayShowActorWithEventMessage : public GameRolePlayShowActorMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayShowActorWithEventMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayShowActorWithEventMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayShowActorWithEventMessage(FuncTree tree);
  GameRolePlayShowActorWithEventMessage();

  uint actorEventId;

private:
  void _actorEventIdFunc(Reader *input);
};

#endif // GAMEROLEPLAYSHOWACTORWITHEVENTMESSAGE_H