#ifndef EXCHANGESTARTOKRECYCLETRADEMESSAGE_H
#define EXCHANGESTARTOKRECYCLETRADEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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

private:
  void _percentToPrismFunc(Reader *input);
  void _percentToPlayerFunc(Reader *input);
};

#endif // EXCHANGESTARTOKRECYCLETRADEMESSAGE_H