#ifndef EXCHANGEREADYMESSAGE_H
#define EXCHANGEREADYMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeReadyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeReadyMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeReadyMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeReadyMessage(FuncTree tree);
  ExchangeReadyMessage();

  bool ready;
  uint step;

private:
  void _readyFunc(Reader *input);
  void _stepFunc(Reader *input);
};

#endif // EXCHANGEREADYMESSAGE_H