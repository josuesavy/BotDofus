#ifndef EXCHANGEREQUESTONTAXCOLLECTORMESSAGE_H
#define EXCHANGEREQUESTONTAXCOLLECTORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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