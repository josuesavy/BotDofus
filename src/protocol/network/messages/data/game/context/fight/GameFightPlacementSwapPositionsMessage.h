#ifndef GAMEFIGHTPLACEMENTSWAPPOSITIONSMESSAGE_H
#define GAMEFIGHTPLACEMENTSWAPPOSITIONSMESSAGE_H

#include "src/protocol/network/types/data/game/context/IdentifiedEntityDispositionInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameFightPlacementSwapPositionsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightPlacementSwapPositionsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightPlacementSwapPositionsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightPlacementSwapPositionsMessage(FuncTree tree);
  GameFightPlacementSwapPositionsMessage();

  QList<QSharedPointer<IdentifiedEntityDispositionInformations>> dispositions;

private:
  void _dispositionstreeFunc(Reader *input);
  void _dispositionsFunc(Reader *input);

  FuncTree _dispositionstree;
  uint _dispositionsindex;
};

#endif // GAMEFIGHTPLACEMENTSWAPPOSITIONSMESSAGE_H