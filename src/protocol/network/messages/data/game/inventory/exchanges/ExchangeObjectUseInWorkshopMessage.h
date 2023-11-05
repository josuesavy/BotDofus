#ifndef EXCHANGEOBJECTUSEINWORKSHOPMESSAGE_H
#define EXCHANGEOBJECTUSEINWORKSHOPMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeObjectUseInWorkshopMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeObjectUseInWorkshopMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeObjectUseInWorkshopMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeObjectUseInWorkshopMessage(FuncTree tree);
  ExchangeObjectUseInWorkshopMessage();

  uint objectUID;
  int quantity;

private:
  void _objectUIDFunc(Reader *input);
  void _quantityFunc(Reader *input);
};

#endif // EXCHANGEOBJECTUSEINWORKSHOPMESSAGE_H