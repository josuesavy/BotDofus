#ifndef EXCHANGEBIDHOUSEBUYMESSAGE_H
#define EXCHANGEBIDHOUSEBUYMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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