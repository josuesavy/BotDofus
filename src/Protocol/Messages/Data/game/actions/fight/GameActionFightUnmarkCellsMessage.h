#ifndef GAMEACTIONFIGHTUNMARKCELLSMESSAGE_H
#define GAMEACTIONFIGHTUNMARKCELLSMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/actions/AbstractGameActionMessage.h"

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