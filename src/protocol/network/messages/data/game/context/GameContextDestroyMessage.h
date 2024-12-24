#ifndef GAMECONTEXTDESTROYMESSAGE_H
#define GAMECONTEXTDESTROYMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameContextDestroyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameContextDestroyMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameContextDestroyMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameContextDestroyMessage(FuncTree tree);
  GameContextDestroyMessage();
};

#endif // GAMECONTEXTDESTROYMESSAGE_H