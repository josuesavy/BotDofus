#ifndef EXCHANGECRAFTINFORMATIONOBJECTMESSAGE_H
#define EXCHANGECRAFTINFORMATIONOBJECTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/exchanges/ExchangeCraftResultWithObjectIdMessage.h"

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