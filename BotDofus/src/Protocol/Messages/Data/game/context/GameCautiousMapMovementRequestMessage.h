#ifndef GAMECAUTIOUSMAPMOVEMENTREQUESTMESSAGE_H
#define GAMECAUTIOUSMAPMOVEMENTREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/GameMapMovementRequestMessage.h"

class GameCautiousMapMovementRequestMessage : public GameMapMovementRequestMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameCautiousMapMovementRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameCautiousMapMovementRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameCautiousMapMovementRequestMessage(FuncTree tree);
  GameCautiousMapMovementRequestMessage();
};

#endif // GAMECAUTIOUSMAPMOVEMENTREQUESTMESSAGE_H