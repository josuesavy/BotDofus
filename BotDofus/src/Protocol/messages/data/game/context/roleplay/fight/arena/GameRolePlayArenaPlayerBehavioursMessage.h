#ifndef GAMEROLEPLAYARENAPLAYERBEHAVIOURSMESSAGE_H
#define GAMEROLEPLAYARENAPLAYERBEHAVIOURSMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameRolePlayArenaPlayerBehavioursMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayArenaPlayerBehavioursMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayArenaPlayerBehavioursMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayArenaPlayerBehavioursMessage(FuncTree tree);
  GameRolePlayArenaPlayerBehavioursMessage();

  QList<QString> flags;
  QList<QString> sanctions;
  uint banDuration;

private:
  void _flagstreeFunc(Reader *input);
  void _flagsFunc(Reader *input);
  void _sanctionstreeFunc(Reader *input);
  void _sanctionsFunc(Reader *input);
  void _banDurationFunc(Reader *input);

  FuncTree _flagstree;
  FuncTree _sanctionstree;
};

#endif // GAMEROLEPLAYARENAPLAYERBEHAVIOURSMESSAGE_H