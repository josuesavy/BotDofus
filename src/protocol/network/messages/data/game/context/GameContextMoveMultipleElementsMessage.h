#ifndef GAMECONTEXTMOVEMULTIPLEELEMENTSMESSAGE_H
#define GAMECONTEXTMOVEMULTIPLEELEMENTSMESSAGE_H

#include "src/protocol/network/types/data/game/context/EntityMovementInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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