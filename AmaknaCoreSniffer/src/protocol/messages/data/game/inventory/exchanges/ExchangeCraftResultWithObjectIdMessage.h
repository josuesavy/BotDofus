#ifndef EXCHANGECRAFTRESULTWITHOBJECTIDMESSAGE_H
#define EXCHANGECRAFTRESULTWITHOBJECTIDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/inventory/exchanges/ExchangeCraftResultMessage.h"

class ExchangeCraftResultWithObjectIdMessage : public ExchangeCraftResultMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeCraftResultWithObjectIdMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeCraftResultWithObjectIdMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeCraftResultWithObjectIdMessage(FuncTree tree);
  ExchangeCraftResultWithObjectIdMessage();

  uint objectGenericId;

private:
  void _objectGenericIdFunc(Reader *input);
};

#endif // EXCHANGECRAFTRESULTWITHOBJECTIDMESSAGE_H