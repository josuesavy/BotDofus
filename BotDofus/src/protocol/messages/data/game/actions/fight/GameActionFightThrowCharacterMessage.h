#ifndef GAMEACTIONFIGHTTHROWCHARACTERMESSAGE_H
#define GAMEACTIONFIGHTTHROWCHARACTERMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/actions/AbstractGameActionMessage.h"

class GameActionFightThrowCharacterMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightThrowCharacterMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightThrowCharacterMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightThrowCharacterMessage(FuncTree tree);
  GameActionFightThrowCharacterMessage();

  double targetId;
  int cellId;

private:
  void _targetIdFunc(Reader *input);
  void _cellIdFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTTHROWCHARACTERMESSAGE_H