#ifndef GAMEROLEPLAYPLAYERFIGHTFRIENDLYANSWERMESSAGE_H
#define GAMEROLEPLAYPLAYERFIGHTFRIENDLYANSWERMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameRolePlayPlayerFightFriendlyAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayPlayerFightFriendlyAnswerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayPlayerFightFriendlyAnswerMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayPlayerFightFriendlyAnswerMessage(FuncTree tree);
  GameRolePlayPlayerFightFriendlyAnswerMessage();

  uint fightId;
  bool accept;

private:
  void _fightIdFunc(Reader *input);
  void _acceptFunc(Reader *input);
};

#endif // GAMEROLEPLAYPLAYERFIGHTFRIENDLYANSWERMESSAGE_H