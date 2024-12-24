#ifndef EXCHANGEMONEYMOVEMENTINFORMATIONMESSAGE_H
#define EXCHANGEMONEYMOVEMENTINFORMATIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeMoneyMovementInformationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeMoneyMovementInformationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeMoneyMovementInformationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeMoneyMovementInformationMessage(FuncTree tree);
  ExchangeMoneyMovementInformationMessage();

  double limit;

private:
  void _limitFunc(Reader *input);
};

#endif // EXCHANGEMONEYMOVEMENTINFORMATIONMESSAGE_H