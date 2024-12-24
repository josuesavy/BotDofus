#ifndef GAMEFIGHTTURNREADYMESSAGE_H
#define GAMEFIGHTTURNREADYMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameFightTurnReadyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightTurnReadyMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightTurnReadyMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightTurnReadyMessage(FuncTree tree);
  GameFightTurnReadyMessage();

  bool isReady;

private:
  void _isReadyFunc(Reader *input);
};

#endif // GAMEFIGHTTURNREADYMESSAGE_H