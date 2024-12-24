#ifndef GAMEROLEPLAYPLAYERFIGHTFRIENDLYREQUESTEDMESSAGE_H
#define GAMEROLEPLAYPLAYERFIGHTFRIENDLYREQUESTEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameRolePlayPlayerFightFriendlyRequestedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayPlayerFightFriendlyRequestedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayPlayerFightFriendlyRequestedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayPlayerFightFriendlyRequestedMessage(FuncTree tree);
  GameRolePlayPlayerFightFriendlyRequestedMessage();

  uint fightId;
  double sourceId;
  double targetId;

private:
  void _fightIdFunc(Reader *input);
  void _sourceIdFunc(Reader *input);
  void _targetIdFunc(Reader *input);
};

#endif // GAMEROLEPLAYPLAYERFIGHTFRIENDLYREQUESTEDMESSAGE_H