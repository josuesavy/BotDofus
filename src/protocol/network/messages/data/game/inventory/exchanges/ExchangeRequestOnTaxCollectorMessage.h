#ifndef EXCHANGEREQUESTONTAXCOLLECTORMESSAGE_H
#define EXCHANGEREQUESTONTAXCOLLECTORMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeRequestOnTaxCollectorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeRequestOnTaxCollectorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeRequestOnTaxCollectorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeRequestOnTaxCollectorMessage(FuncTree tree);
  ExchangeRequestOnTaxCollectorMessage();
};

#endif // EXCHANGEREQUESTONTAXCOLLECTORMESSAGE_H