#ifndef GAMEFIGHTPLACEMENTSWAPPOSITIONSREQUESTMESSAGE_H
#define GAMEFIGHTPLACEMENTSWAPPOSITIONSREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/fight/GameFightPlacementPositionRequestMessage.h"

class GameFightPlacementSwapPositionsRequestMessage : public GameFightPlacementPositionRequestMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightPlacementSwapPositionsRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightPlacementSwapPositionsRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightPlacementSwapPositionsRequestMessage(FuncTree tree);
  GameFightPlacementSwapPositionsRequestMessage();

  double requestedId;

private:
  void _requestedIdFunc(Reader *input);
};

#endif // GAMEFIGHTPLACEMENTSWAPPOSITIONSREQUESTMESSAGE_H