#ifndef GAMEFIGHTREADYMESSAGE_H
#define GAMEFIGHTREADYMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameFightReadyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightReadyMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightReadyMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightReadyMessage(FuncTree tree);
  GameFightReadyMessage();

  bool isReady;

private:
  void _isReadyFunc(Reader *input);
};

#endif // GAMEFIGHTREADYMESSAGE_H