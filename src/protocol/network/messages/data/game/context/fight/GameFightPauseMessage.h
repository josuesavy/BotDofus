#ifndef GAMEFIGHTPAUSEMESSAGE_H
#define GAMEFIGHTPAUSEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameFightPauseMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightPauseMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightPauseMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightPauseMessage(FuncTree tree);
  GameFightPauseMessage();

  bool isPaused;

private:
  void _isPausedFunc(Reader *input);
};

#endif // GAMEFIGHTPAUSEMESSAGE_H