#ifndef GAMECONTEXTQUITMESSAGE_H
#define GAMECONTEXTQUITMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameContextQuitMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameContextQuitMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameContextQuitMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameContextQuitMessage(FuncTree tree);
  GameContextQuitMessage();
};

#endif // GAMECONTEXTQUITMESSAGE_H