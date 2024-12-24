#ifndef EXCHANGESTARTEDTAXCOLLECTOREQUIPMENTMESSAGE_H
#define EXCHANGESTARTEDTAXCOLLECTOREQUIPMENTMESSAGE_H

#include "src/protocol/network/types/data/game/collector/tax/TaxCollectorInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeStartedTaxCollectorEquipmentMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeStartedTaxCollectorEquipmentMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeStartedTaxCollectorEquipmentMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeStartedTaxCollectorEquipmentMessage(FuncTree tree);
  ExchangeStartedTaxCollectorEquipmentMessage();

  QSharedPointer<TaxCollectorInformations> information;

private:
  void _informationtreeFunc(Reader *input);

  FuncTree _informationtree;
};

#endif // EXCHANGESTARTEDTAXCOLLECTOREQUIPMENTMESSAGE_H