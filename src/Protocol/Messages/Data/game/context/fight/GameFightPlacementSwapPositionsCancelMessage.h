#ifndef GAMEFIGHTPLACEMENTSWAPPOSITIONSCANCELMESSAGE_H
#define GAMEFIGHTPLACEMENTSWAPPOSITIONSCANCELMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameFightPlacementSwapPositionsCancelMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightPlacementSwapPositionsCancelMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightPlacementSwapPositionsCancelMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightPlacementSwapPositionsCancelMessage(FuncTree tree);
  GameFightPlacementSwapPositionsCancelMessage();

  uint requestId;

private:
  void _requestIdFunc(Reader *input);
};

#endif // GAMEFIGHTPLACEMENTSWAPPOSITIONSCANCELMESSAGE_H