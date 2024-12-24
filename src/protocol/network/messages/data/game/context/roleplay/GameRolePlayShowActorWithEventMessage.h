#ifndef GAMEROLEPLAYSHOWACTORWITHEVENTMESSAGE_H
#define GAMEROLEPLAYSHOWACTORWITHEVENTMESSAGE_H

#include "src/protocol/network/types/data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/context/roleplay/GameRolePlayShowActorMessage.h"

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