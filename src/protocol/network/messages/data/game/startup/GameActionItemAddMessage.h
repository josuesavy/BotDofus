#ifndef GAMEACTIONITEMADDMESSAGE_H
#define GAMEACTIONITEMADDMESSAGE_H

#include "src/protocol/network/types/data/game/startup/GameActionItem.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameActionItemAddMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionItemAddMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionItemAddMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionItemAddMessage(FuncTree tree);
  GameActionItemAddMessage();

  QSharedPointer<GameActionItem> newAction;

private:
  void _newActiontreeFunc(Reader *input);

  FuncTree _newActiontree;
};

#endif // GAMEACTIONITEMADDMESSAGE_H