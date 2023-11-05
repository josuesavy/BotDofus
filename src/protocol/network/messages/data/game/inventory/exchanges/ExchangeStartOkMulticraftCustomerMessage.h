#ifndef EXCHANGESTARTOKMULTICRAFTCUSTOMERMESSAGE_H
#define EXCHANGESTARTOKMULTICRAFTCUSTOMERMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeStartOkMulticraftCustomerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeStartOkMulticraftCustomerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeStartOkMulticraftCustomerMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeStartOkMulticraftCustomerMessage(FuncTree tree);
  ExchangeStartOkMulticraftCustomerMessage();

  uint skillId;
  uint crafterJobLevel;

private:
  void _skillIdFunc(Reader *input);
  void _crafterJobLevelFunc(Reader *input);
};

#endif // EXCHANGESTARTOKMULTICRAFTCUSTOMERMESSAGE_H