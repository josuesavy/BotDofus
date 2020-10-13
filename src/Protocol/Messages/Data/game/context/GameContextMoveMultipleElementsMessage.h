#ifndef GAMECONTEXTMOVEMULTIPLEELEMENTSMESSAGE_H
#define GAMECONTEXTMOVEMULTIPLEELEMENTSMESSAGE_H

#include "src/Protocol/Types/Data/game/context/EntityMovementInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameContextMoveMultipleElementsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameContextMoveMultipleElementsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameContextMoveMultipleElementsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameContextMoveMultipleElementsMessage(FuncTree tree);
  GameContextMoveMultipleElementsMessage();

  QList<EntityMovementInformations> movements;

private:
  void _movementstreeFunc(Reader *input);
  void _movementsFunc(Reader *input);

  FuncTree _movementstree;
};

#endif // GAMECONTEXTMOVEMULTIPLEELEMENTSMESSAGE_H