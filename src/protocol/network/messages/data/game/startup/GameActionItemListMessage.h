#ifndef GAMEACTIONITEMLISTMESSAGE_H
#define GAMEACTIONITEMLISTMESSAGE_H

#include "src/protocol/network/types/data/game/startup/GameActionItem.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameActionItemListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionItemListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionItemListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionItemListMessage(FuncTree tree);
  GameActionItemListMessage();

  QList<QSharedPointer<GameActionItem>> actions;

private:
  void _actionstreeFunc(Reader *input);
  void _actionsFunc(Reader *input);

  FuncTree _actionstree;
};

#endif // GAMEACTIONITEMLISTMESSAGE_H