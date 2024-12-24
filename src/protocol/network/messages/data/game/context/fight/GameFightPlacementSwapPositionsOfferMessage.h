#ifndef GAMEFIGHTPLACEMENTSWAPPOSITIONSOFFERMESSAGE_H
#define GAMEFIGHTPLACEMENTSWAPPOSITIONSOFFERMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameFightPlacementSwapPositionsOfferMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightPlacementSwapPositionsOfferMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightPlacementSwapPositionsOfferMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightPlacementSwapPositionsOfferMessage(FuncTree tree);
  GameFightPlacementSwapPositionsOfferMessage();

  uint requestId;
  double requesterId;
  uint requesterCellId;
  double requestedId;
  uint requestedCellId;

private:
  void _requestIdFunc(Reader *input);
  void _requesterIdFunc(Reader *input);
  void _requesterCellIdFunc(Reader *input);
  void _requestedIdFunc(Reader *input);
  void _requestedCellIdFunc(Reader *input);
};

#endif // GAMEFIGHTPLACEMENTSWAPPOSITIONSOFFERMESSAGE_H