#ifndef EXCHANGECRAFTPAYMENTMODIFICATIONREQUESTMESSAGE_H
#define EXCHANGECRAFTPAYMENTMODIFICATIONREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeCraftPaymentModificationRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeCraftPaymentModificationRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeCraftPaymentModificationRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeCraftPaymentModificationRequestMessage(FuncTree tree);
  ExchangeCraftPaymentModificationRequestMessage();

  double quantity;

private:
  void _quantityFunc(Reader *input);
};

#endif // EXCHANGECRAFTPAYMENTMODIFICATIONREQUESTMESSAGE_H