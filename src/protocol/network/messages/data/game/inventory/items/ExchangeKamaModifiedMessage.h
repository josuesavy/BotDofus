#ifndef EXCHANGEKAMAMODIFIEDMESSAGE_H
#define EXCHANGEKAMAMODIFIEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/inventory/exchanges/ExchangeObjectMessage.h"

class ExchangeKamaModifiedMessage : public ExchangeObjectMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeKamaModifiedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeKamaModifiedMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeKamaModifiedMessage(FuncTree tree);
  ExchangeKamaModifiedMessage();

  double quantity;

private:
  void _quantityFunc(Reader *input);
};

#endif // EXCHANGEKAMAMODIFIEDMESSAGE_H