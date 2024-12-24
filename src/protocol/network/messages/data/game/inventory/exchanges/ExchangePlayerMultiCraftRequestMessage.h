#ifndef EXCHANGEPLAYERMULTICRAFTREQUESTMESSAGE_H
#define EXCHANGEPLAYERMULTICRAFTREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/inventory/exchanges/ExchangeRequestMessage.h"

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