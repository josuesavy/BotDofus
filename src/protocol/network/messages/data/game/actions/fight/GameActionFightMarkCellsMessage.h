#ifndef GAMEACTIONFIGHTMARKCELLSMESSAGE_H
#define GAMEACTIONFIGHTMARKCELLSMESSAGE_H

#include "src/protocol/network/types/data/game/actions/fight/GameActionMark.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/actions/AbstractGameActionMessage.h"

class GameActionFightMarkCellsMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightMarkCellsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightMarkCellsMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightMarkCellsMessage(FuncTree tree);
  GameActionFightMarkCellsMessage();

  GameActionMark mark;

private:
  void _marktreeFunc(Reader *input);

  FuncTree _marktree;
};

#endif // GAMEACTIONFIGHTMARKCELLSMESSAGE_H