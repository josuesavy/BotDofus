#ifndef EXCHANGEWAITINGRESULTMESSAGE_H
#define EXCHANGEWAITINGRESULTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeWaitingResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeWaitingResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeWaitingResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeWaitingResultMessage(FuncTree tree);
  ExchangeWaitingResultMessage();

  bool bwait;

private:
  void _bwaitFunc(Reader *input);
};

#endif // EXCHANGEWAITINGRESULTMESSAGE_H