#ifndef EXCHANGECRAFTPAYMENTMODIFIEDMESSAGE_H
#define EXCHANGECRAFTPAYMENTMODIFIEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeCraftPaymentModifiedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeCraftPaymentModifiedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeCraftPaymentModifiedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeCraftPaymentModifiedMessage(FuncTree tree);
  ExchangeCraftPaymentModifiedMessage();

  double goldSum;

private:
  void _goldSumFunc(Reader *input);
};

#endif // EXCHANGECRAFTPAYMENTMODIFIEDMESSAGE_H