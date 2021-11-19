#ifndef EXCHANGEBIDHOUSEBUYMESSAGE_H
#define EXCHANGEBIDHOUSEBUYMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeBidHouseBuyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeBidHouseBuyMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeBidHouseBuyMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeBidHouseBuyMessage(FuncTree tree);
  ExchangeBidHouseBuyMessage();

  uint uid;
  uint qty;
  double price;

private:
  void _uidFunc(Reader *input);
  void _qtyFunc(Reader *input);
  void _priceFunc(Reader *input);
};

#endif // EXCHANGEBIDHOUSEBUYMESSAGE_H