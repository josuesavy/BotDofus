#ifndef GAMEROLEPLAYREMOVECHALLENGEMESSAGE_H
#define GAMEROLEPLAYREMOVECHALLENGEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameRolePlayRemoveChallengeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayRemoveChallengeMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayRemoveChallengeMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayRemoveChallengeMessage(FuncTree tree);
  GameRolePlayRemoveChallengeMessage();

  uint fightId;

private:
  void _fightIdFunc(Reader *input);
};

#endif // GAMEROLEPLAYREMOVECHALLENGEMESSAGE_H