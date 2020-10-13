#ifndef FOCUSEDEXCHANGEREADYMESSAGE_H
#define FOCUSEDEXCHANGEREADYMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/exchanges/ExchangeReadyMessage.h"

class FocusedExchangeReadyMessage : public ExchangeReadyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FocusedExchangeReadyMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FocusedExchangeReadyMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FocusedExchangeReadyMessage(FuncTree tree);
  FocusedExchangeReadyMessage();

  uint focusActionId;

private:
  void _focusActionIdFunc(Reader *input);
};

#endif // FOCUSEDEXCHANGEREADYMESSAGE_H