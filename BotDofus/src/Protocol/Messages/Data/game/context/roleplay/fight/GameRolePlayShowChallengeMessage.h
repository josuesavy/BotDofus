#ifndef GAMEROLEPLAYSHOWCHALLENGEMESSAGE_H
#define GAMEROLEPLAYSHOWCHALLENGEMESSAGE_H

#include "src/Protocol/Types/Data/game/context/fight/FightCommonInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameRolePlayShowChallengeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayShowChallengeMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayShowChallengeMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayShowChallengeMessage(FuncTree tree);
  GameRolePlayShowChallengeMessage();

  QSharedPointer<FightCommonInformations> commonsInfos;

private:
  void _commonsInfostreeFunc(Reader *input);

  FuncTree _commonsInfostree;
};

#endif // GAMEROLEPLAYSHOWCHALLENGEMESSAGE_H