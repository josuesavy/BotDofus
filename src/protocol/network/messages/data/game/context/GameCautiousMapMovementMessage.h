#ifndef GAMECAUTIOUSMAPMOVEMENTMESSAGE_H
#define GAMECAUTIOUSMAPMOVEMENTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/context/GameMapMovementMessage.h"

class GameCautiousMapMovementMessage : public GameMapMovementMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameCautiousMapMovementMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameCautiousMapMovementMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameCautiousMapMovementMessage(FuncTree tree);
  GameCautiousMapMovementMessage();
};

#endif // GAMECAUTIOUSMAPMOVEMENTMESSAGE_H