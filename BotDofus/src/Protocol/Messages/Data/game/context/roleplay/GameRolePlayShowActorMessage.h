#ifndef GAMEROLEPLAYSHOWACTORMESSAGE_H
#define GAMEROLEPLAYSHOWACTORMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameRolePlayShowActorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayShowActorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayShowActorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayShowActorMessage(FuncTree tree);
  GameRolePlayShowActorMessage();

  QSharedPointer<GameRolePlayActorInformations> informations;

private:
  void _informationstreeFunc(Reader *input);

  FuncTree _informationstree;
};

#endif // GAMEROLEPLAYSHOWACTORMESSAGE_H