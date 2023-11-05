#ifndef GAMEROLEPLAYSHOWCHALLENGEMESSAGE_H
#define GAMEROLEPLAYSHOWCHALLENGEMESSAGE_H

#include "src/protocol/types/data/game/context/fight/FightCommonInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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

  FightCommonInformations commonsInfos;

private:
  void _commonsInfostreeFunc(Reader *input);

  FuncTree _commonsInfostree;
};

#endif // GAMEROLEPLAYSHOWCHALLENGEMESSAGE_H