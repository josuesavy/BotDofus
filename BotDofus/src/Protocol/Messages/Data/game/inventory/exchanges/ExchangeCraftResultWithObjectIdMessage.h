#ifndef EXCHANGECRAFTRESULTWITHOBJECTIDMESSAGE_H
#define EXCHANGECRAFTRESULTWITHOBJECTIDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/exchanges/ExchangeCraftResultMessage.h"

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