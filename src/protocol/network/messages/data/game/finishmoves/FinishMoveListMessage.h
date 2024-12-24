#ifndef FINISHMOVELISTMESSAGE_H
#define FINISHMOVELISTMESSAGE_H

#include "src/protocol/network/types/data/game/finishmoves/FinishMoveInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class FinishMoveListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FinishMoveListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FinishMoveListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FinishMoveListMessage(FuncTree tree);
  FinishMoveListMessage();

  QList<FinishMoveInformations> finishMoves;

private:
  void _finishMovestreeFunc(Reader *input);
  void _finishMovesFunc(Reader *input);

  FuncTree _finishMovestree;
};

#endif // FINISHMOVELISTMESSAGE_H