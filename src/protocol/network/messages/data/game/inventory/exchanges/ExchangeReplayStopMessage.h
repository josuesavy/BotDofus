#ifndef EXCHANGEREPLAYSTOPMESSAGE_H
#define EXCHANGEREPLAYSTOPMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeReplayStopMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeReplayStopMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeReplayStopMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeReplayStopMessage(FuncTree tree);
  ExchangeReplayStopMessage();
};

#endif // EXCHANGEREPLAYSTOPMESSAGE_H