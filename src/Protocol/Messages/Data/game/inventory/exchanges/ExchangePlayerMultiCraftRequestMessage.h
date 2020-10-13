#ifndef EXCHANGEPLAYERMULTICRAFTREQUESTMESSAGE_H
#define EXCHANGEPLAYERMULTICRAFTREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/exchanges/ExchangeRequestMessage.h"

class ExchangePlayerMultiCraftRequestMessage : public ExchangeRequestMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangePlayerMultiCraftRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangePlayerMultiCraftRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangePlayerMultiCraftRequestMessage(FuncTree tree);
  ExchangePlayerMultiCraftRequestMessage();

  double target;
  uint skillId;

private:
  void _targetFunc(Reader *input);
  void _skillIdFunc(Reader *input);
};

#endif // EXCHANGEPLAYERMULTICRAFTREQUESTMESSAGE_H