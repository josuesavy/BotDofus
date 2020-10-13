#ifndef EXCHANGESTARTOKRUNESTRADEMESSAGE_H
#define EXCHANGESTARTOKRUNESTRADEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeStartOkRunesTradeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeStartOkRunesTradeMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeStartOkRunesTradeMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeStartOkRunesTradeMessage(FuncTree tree);
  ExchangeStartOkRunesTradeMessage();
};

#endif // EXCHANGESTARTOKRUNESTRADEMESSAGE_H