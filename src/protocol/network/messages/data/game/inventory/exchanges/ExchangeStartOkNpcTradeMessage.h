#ifndef EXCHANGESTARTOKNPCTRADEMESSAGE_H
#define EXCHANGESTARTOKNPCTRADEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeStartOkNpcTradeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeStartOkNpcTradeMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeStartOkNpcTradeMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeStartOkNpcTradeMessage(FuncTree tree);
  ExchangeStartOkNpcTradeMessage();

  double npcId;

private:
  void _npcIdFunc(Reader *input);
};

#endif // EXCHANGESTARTOKNPCTRADEMESSAGE_H