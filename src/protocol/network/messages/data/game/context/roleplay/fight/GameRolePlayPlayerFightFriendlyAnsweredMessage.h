#ifndef GAMEROLEPLAYPLAYERFIGHTFRIENDLYANSWEREDMESSAGE_H
#define GAMEROLEPLAYPLAYERFIGHTFRIENDLYANSWEREDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameRolePlayPlayerFightFriendlyAnsweredMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayPlayerFightFriendlyAnsweredMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayPlayerFightFriendlyAnsweredMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayPlayerFightFriendlyAnsweredMessage(FuncTree tree);
  GameRolePlayPlayerFightFriendlyAnsweredMessage();

  uint fightId;
  double sourceId;
  double targetId;
  bool accept;

private:
  void _fightIdFunc(Reader *input);
  void _sourceIdFunc(Reader *input);
  void _targetIdFunc(Reader *input);
  void _acceptFunc(Reader *input);
};

#endif // GAMEROLEPLAYPLAYERFIGHTFRIENDLYANSWEREDMESSAGE_H