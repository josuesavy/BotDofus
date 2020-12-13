#ifndef FOCUSEDEXCHANGEREADYMESSAGE_H
#define FOCUSEDEXCHANGEREADYMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/inventory/exchanges/ExchangeReadyMessage.h"

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