#ifndef EXCHANGEITEMAUTOCRAFTSTOPEDMESSAGE_H
#define EXCHANGEITEMAUTOCRAFTSTOPEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeItemAutoCraftStopedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeItemAutoCraftStopedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeItemAutoCraftStopedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeItemAutoCraftStopedMessage(FuncTree tree);
  ExchangeItemAutoCraftStopedMessage();

  int reason;

private:
  void _reasonFunc(Reader *input);
};

#endif // EXCHANGEITEMAUTOCRAFTSTOPEDMESSAGE_H