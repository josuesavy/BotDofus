#ifndef GAMECONTEXTDESTROYMESSAGE_H
#define GAMECONTEXTDESTROYMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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