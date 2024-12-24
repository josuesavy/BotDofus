#ifndef EXCHANGESTARTOKCRAFTWITHINFORMATIONMESSAGE_H
#define EXCHANGESTARTOKCRAFTWITHINFORMATIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/inventory/exchanges/ExchangeStartOkCraftMessage.h"

class ExchangeStartOkCraftWithInformationMessage : public ExchangeStartOkCraftMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeStartOkCraftWithInformationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeStartOkCraftWithInformationMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeStartOkCraftWithInformationMessage(FuncTree tree);
  ExchangeStartOkCraftWithInformationMessage();

  uint skillId;

private:
  void _skillIdFunc(Reader *input);
};

#endif // EXCHANGESTARTOKCRAFTWITHINFORMATIONMESSAGE_H