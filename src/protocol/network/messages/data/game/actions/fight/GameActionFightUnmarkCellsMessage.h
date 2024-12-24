#ifndef GAMEACTIONFIGHTUNMARKCELLSMESSAGE_H
#define GAMEACTIONFIGHTUNMARKCELLSMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/actions/AbstractGameActionMessage.h"

class GameActionFightUnmarkCellsMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightUnmarkCellsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightUnmarkCellsMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightUnmarkCellsMessage(FuncTree tree);
  GameActionFightUnmarkCellsMessage();

  int markId;

private:
  void _markIdFunc(Reader *input);
};

#endif // GAMEACTIONFIGHTUNMARKCELLSMESSAGE_H