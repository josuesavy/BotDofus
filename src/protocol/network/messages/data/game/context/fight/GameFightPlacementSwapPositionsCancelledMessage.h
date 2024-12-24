#ifndef GAMEFIGHTPLACEMENTSWAPPOSITIONSCANCELLEDMESSAGE_H
#define GAMEFIGHTPLACEMENTSWAPPOSITIONSCANCELLEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameFightPlacementSwapPositionsCancelledMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightPlacementSwapPositionsCancelledMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightPlacementSwapPositionsCancelledMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightPlacementSwapPositionsCancelledMessage(FuncTree tree);
  GameFightPlacementSwapPositionsCancelledMessage();

  uint requestId;
  double cancellerId;

private:
  void _requestIdFunc(Reader *input);
  void _cancellerIdFunc(Reader *input);
};

#endif // GAMEFIGHTPLACEMENTSWAPPOSITIONSCANCELLEDMESSAGE_H