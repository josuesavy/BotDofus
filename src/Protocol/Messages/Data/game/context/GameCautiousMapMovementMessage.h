#ifndef GAMECAUTIOUSMAPMOVEMENTMESSAGE_H
#define GAMECAUTIOUSMAPMOVEMENTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/GameMapMovementMessage.h"

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