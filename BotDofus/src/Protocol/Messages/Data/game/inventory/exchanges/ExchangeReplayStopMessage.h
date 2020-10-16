#ifndef EXCHANGEREPLAYSTOPMESSAGE_H
#define EXCHANGEREPLAYSTOPMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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