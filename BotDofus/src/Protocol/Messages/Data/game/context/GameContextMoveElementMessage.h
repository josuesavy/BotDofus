#ifndef GAMECONTEXTMOVEELEMENTMESSAGE_H
#define GAMECONTEXTMOVEELEMENTMESSAGE_H

#include "src/Protocol/Types/Data/game/context/EntityMovementInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameContextMoveElementMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameContextMoveElementMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameContextMoveElementMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameContextMoveElementMessage(FuncTree tree);
  GameContextMoveElementMessage();

  EntityMovementInformations movement;

private:
  void _movementtreeFunc(Reader *input);

  FuncTree _movementtree;
};

#endif // GAMECONTEXTMOVEELEMENTMESSAGE_H