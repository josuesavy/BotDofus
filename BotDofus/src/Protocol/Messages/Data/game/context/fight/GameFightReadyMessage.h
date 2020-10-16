#ifndef GAMEFIGHTREADYMESSAGE_H
#define GAMEFIGHTREADYMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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