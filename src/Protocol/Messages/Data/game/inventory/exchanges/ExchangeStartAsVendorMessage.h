#ifndef EXCHANGESTARTASVENDORMESSAGE_H
#define EXCHANGESTARTASVENDORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeStartAsVendorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeStartAsVendorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeStartAsVendorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeStartAsVendorMessage(FuncTree tree);
  ExchangeStartAsVendorMessage();
};

#endif // EXCHANGESTARTASVENDORMESSAGE_H