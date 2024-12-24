#ifndef GAMEACTIONFIGHTCARRYCHARACTERMESSAGE_H
#define GAMEACTIONFIGHTCARRYCHARACTERMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/actions/AbstractGameActionMessage.h"

class GameActionFightCarryCharacterMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightCarryCharacterMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightCarryCharacterMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightCarryCharacterMessage(FuncTree tree);
  GameActionFightCarryCharacterMessage();

  double targetId;
  int cellId;

private:
  void _targetIdFunc(Reader *input);
  void _cellIdFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTCARRYCHARACTERMESSAGE_H