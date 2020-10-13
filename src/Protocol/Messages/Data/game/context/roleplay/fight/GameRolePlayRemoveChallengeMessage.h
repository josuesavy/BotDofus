#ifndef GAMEROLEPLAYREMOVECHALLENGEMESSAGE_H
#define GAMEROLEPLAYREMOVECHALLENGEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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