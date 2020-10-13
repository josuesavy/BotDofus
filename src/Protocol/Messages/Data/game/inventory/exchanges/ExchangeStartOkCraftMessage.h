#ifndef EXCHANGESTARTOKCRAFTMESSAGE_H
#define EXCHANGESTARTOKCRAFTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeStartOkCraftMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeStartOkCraftMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeStartOkCraftMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeStartOkCraftMessage(FuncTree tree);
  ExchangeStartOkCraftMessage();
};

#endif // EXCHANGESTARTOKCRAFTMESSAGE_H