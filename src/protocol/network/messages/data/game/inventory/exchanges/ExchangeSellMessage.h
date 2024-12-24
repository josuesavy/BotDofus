#ifndef EXCHANGESELLMESSAGE_H
#define EXCHANGESELLMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeSellMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeSellMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeSellMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeSellMessage(FuncTree tree);
  ExchangeSellMessage();

  uint objectToSellId;
  uint quantity;

private:
  void _objectToSellIdFunc(Reader *input);
  void _quantityFunc(Reader *input);
};

#endif // EXCHANGESELLMESSAGE_H