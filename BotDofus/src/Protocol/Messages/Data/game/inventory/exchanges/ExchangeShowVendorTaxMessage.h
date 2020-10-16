#ifndef EXCHANGESHOWVENDORTAXMESSAGE_H
#define EXCHANGESHOWVENDORTAXMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeShowVendorTaxMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeShowVendorTaxMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeShowVendorTaxMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeShowVendorTaxMessage(FuncTree tree);
  ExchangeShowVendorTaxMessage();
};

#endif // EXCHANGESHOWVENDORTAXMESSAGE_H