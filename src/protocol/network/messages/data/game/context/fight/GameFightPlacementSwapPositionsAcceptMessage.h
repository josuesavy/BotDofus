#ifndef GAMEFIGHTPLACEMENTSWAPPOSITIONSACCEPTMESSAGE_H
#define GAMEFIGHTPLACEMENTSWAPPOSITIONSACCEPTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameFightPlacementSwapPositionsAcceptMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightPlacementSwapPositionsAcceptMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightPlacementSwapPositionsAcceptMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightPlacementSwapPositionsAcceptMessage(FuncTree tree);
  GameFightPlacementSwapPositionsAcceptMessage();

  uint requestId;

private:
  void _requestIdFunc(Reader *input);
};

#endif // GAMEFIGHTPLACEMENTSWAPPOSITIONSACCEPTMESSAGE_H