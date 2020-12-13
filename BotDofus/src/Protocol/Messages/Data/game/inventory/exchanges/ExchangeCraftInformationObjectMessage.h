#ifndef EXCHANGECRAFTINFORMATIONOBJECTMESSAGE_H
#define EXCHANGECRAFTINFORMATIONOBJECTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/inventory/exchanges/ExchangeCraftResultWithObjectIdMessage.h"

class ExchangeCraftInformationObjectMessage : public ExchangeCraftResultWithObjectIdMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeCraftInformationObjectMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeCraftInformationObjectMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeCraftInformationObjectMessage(FuncTree tree);
  ExchangeCraftInformationObjectMessage();

  double playerId;

private:
  void _playerIdFunc(Reader *input);
};

#endif // EXCHANGECRAFTINFORMATIONOBJECTMESSAGE_H