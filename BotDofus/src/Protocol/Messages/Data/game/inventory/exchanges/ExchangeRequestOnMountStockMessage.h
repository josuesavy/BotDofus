#ifndef EXCHANGEREQUESTONMOUNTSTOCKMESSAGE_H
#define EXCHANGEREQUESTONMOUNTSTOCKMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeRequestOnMountStockMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeRequestOnMountStockMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeRequestOnMountStockMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeRequestOnMountStockMessage(FuncTree tree);
  ExchangeRequestOnMountStockMessage();
};

#endif // EXCHANGEREQUESTONMOUNTSTOCKMESSAGE_H