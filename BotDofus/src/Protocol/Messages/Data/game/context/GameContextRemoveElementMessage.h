#ifndef GAMECONTEXTREMOVEELEMENTMESSAGE_H
#define GAMECONTEXTREMOVEELEMENTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameContextRemoveElementMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameContextRemoveElementMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameContextRemoveElementMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameContextRemoveElementMessage(FuncTree tree);
  GameContextRemoveElementMessage();

  double id;

private:
  void _idFunc(Reader *input);
};

#endif // GAMECONTEXTREMOVEELEMENTMESSAGE_H