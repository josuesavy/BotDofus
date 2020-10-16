#ifndef GAMEFIGHTPLACEMENTSWAPPOSITIONSERRORMESSAGE_H
#define GAMEFIGHTPLACEMENTSWAPPOSITIONSERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameFightPlacementSwapPositionsErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightPlacementSwapPositionsErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightPlacementSwapPositionsErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightPlacementSwapPositionsErrorMessage(FuncTree tree);
  GameFightPlacementSwapPositionsErrorMessage();
};

#endif // GAMEFIGHTPLACEMENTSWAPPOSITIONSERRORMESSAGE_H