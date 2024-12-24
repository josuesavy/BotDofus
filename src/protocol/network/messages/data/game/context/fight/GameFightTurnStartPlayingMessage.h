#ifndef GAMEFIGHTTURNSTARTPLAYINGMESSAGE_H
#define GAMEFIGHTTURNSTARTPLAYINGMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameFightTurnStartPlayingMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightTurnStartPlayingMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightTurnStartPlayingMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightTurnStartPlayingMessage(FuncTree tree);
  GameFightTurnStartPlayingMessage();
};

#endif // GAMEFIGHTTURNSTARTPLAYINGMESSAGE_H