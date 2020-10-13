#ifndef GAMEFIGHTTURNSTARTPLAYINGMESSAGE_H
#define GAMEFIGHTTURNSTARTPLAYINGMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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