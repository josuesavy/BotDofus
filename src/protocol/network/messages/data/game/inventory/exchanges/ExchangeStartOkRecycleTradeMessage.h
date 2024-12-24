#ifndef EXCHANGESTARTOKRECYCLETRADEMESSAGE_H
#define EXCHANGESTARTOKRECYCLETRADEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeStartOkRecycleTradeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeStartOkRecycleTradeMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeStartOkRecycleTradeMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeStartOkRecycleTradeMessage(FuncTree tree);
  ExchangeStartOkRecycleTradeMessage();

  uint percentToPrism;
  uint percentToPlayer;
  QList<uint> adjacentSubareaPossessed;
  QList<uint> adjacentSubareaUnpossessed;

private:
  void _percentToPrismFunc(Reader *input);
  void _percentToPlayerFunc(Reader *input);
  void _adjacentSubareaPossessedtreeFunc(Reader *input);
  void _adjacentSubareaPossessedFunc(Reader *input);
  void _adjacentSubareaUnpossessedtreeFunc(Reader *input);
  void _adjacentSubareaUnpossessedFunc(Reader *input);

  FuncTree _adjacentSubareaPossessedtree;
  FuncTree _adjacentSubareaUnpossessedtree;
};

#endif // EXCHANGESTARTOKRECYCLETRADEMESSAGE_H