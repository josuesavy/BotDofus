#ifndef GAMEACTIONSPAMMESSAGE_H
#define GAMEACTIONSPAMMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameActionSpamMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionSpamMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionSpamMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionSpamMessage(FuncTree tree);
  GameActionSpamMessage();

  QList<int> cells;

private:
  void _cellstreeFunc(Reader *input);
  void _cellsFunc(Reader *input);

  FuncTree _cellstree;
};

#endif // GAMEACTIONSPAMMESSAGE_H