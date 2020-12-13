#ifndef EXCHANGEREPLYTAXVENDORMESSAGE_H
#define EXCHANGEREPLYTAXVENDORMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeReplyTaxVendorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeReplyTaxVendorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeReplyTaxVendorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeReplyTaxVendorMessage(FuncTree tree);
  ExchangeReplyTaxVendorMessage();

  double objectValue;
  double totalTaxValue;

private:
  void _objectValueFunc(Reader *input);
  void _totalTaxValueFunc(Reader *input);
};

#endif // EXCHANGEREPLYTAXVENDORMESSAGE_H